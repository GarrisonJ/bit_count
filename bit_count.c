#include <ruby.h>

unsigned int bit_count(long value) {
#ifdef __GNUC__
    // Use GCC built-in
    return __builtin_popcountl(labs(value));
#else
    // Fallback method for compilers without the built-in
    unsigned int count = 0;
    while (value) {
        count += value & 1;
        value >>= 1;
    }
    return count;
#endif
}

// Wrapper function for Ruby
VALUE rb_bit_count(VALUE self) {
    long value = NUM2LONG(self);
    unsigned int count =  bit_count(value);
    return UINT2NUM(count);
}

void Init_bit_count() {
    rb_define_method(rb_cInteger, "bit_count", rb_bit_count, 0);
}
