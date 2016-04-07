primes = [3, 7, 31, 127, 2047]

File.open(ARGV[0]).each_line do |line|
  arr = []
  primes.each do |x|
    arr << x if x < line.to_i
  end

  puts arr.join(', ')
end
