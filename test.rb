require 'bit_count'


(0..1000).each do |n|
  if n.bit_count != n.to_s(2).count("1")
    puts "#{n} failed because n.bit_count was #{n.bit_count} and n.to_s(2).count('1') was #{n.to_s(2).count("1")}"
    break
  end
  if n.bit_count != (-n).bit_count
    puts "#{n} failed because n.bit_count was #{n.bit_count} and (-n).bit_count was #{(-n).bit_count}"
    break
  end
end

puts "All tests passed"
