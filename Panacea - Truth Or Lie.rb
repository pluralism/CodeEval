File.open(ARGV[0]).each_line do |line|
  arr = line.split('|').map(&:strip)
  virus = arr[0].split.map { |n| n.to_i(16) }.inject { |sum, n| sum + n }
  antivirus = arr[1].split.map { |n| n.to_i(2) }.inject { |sum, n| sum + n }

  if antivirus >= virus
    puts "True"
  else
    puts "False"
  end
end
