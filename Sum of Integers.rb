File.open(ARGV[0]).each_line do |line|
  arr = line.split(',').map(&:to_i)

  current_max = arr[0]
  global_max = arr[0]
  for i in 1...arr.length
    current_max = [current_max + arr[i], arr[i]].max
    global_max = [current_max, global_max].max
  end
  puts global_max
end
