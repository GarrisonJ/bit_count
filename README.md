# A Ruby Population Count for Integers

`n.bit_count` is equivalent to `n.to_s(2).count('1')` but much faster.

```
(0..10_000_000).each { |x| x.to_s(2).count('1') }
processing time: 3.877620s

(0..10_000_000).each { |x| x.bit_count }
processing time: 0.529214s
```
