def calculate(line)
  arr = line.split(';')
  words = arr[0].split
  index = arr[1].split
  
  hash_table = { }
  for i in 0...index.size
    hash_table[index[i].to_i] = words[i]
  end
  
  
  for i in 0...words.size
    if hash_table[i + 1].nil?
      hash_table[i + 1] = words[words.size - 1]
    end
  end
  
  final_string = ""
  hash_table.sort.map do |k, v|
    final_string << v << " "
  end
  puts final_string[0..-2]
end

File.open(ARGV[0]).each_line do |line|
  calculate(line)
end