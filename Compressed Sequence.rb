def calculate(line)
  arr = line.split
  last_element = arr[0]
  final_string = ""
  count = 0
  
  arr.each_with_index do |element, index|
    if element == last_element
      count += 1
      last_element = element
    else
      final_string << count.to_s << " " << last_element << " "
      count = 1
      last_element = element
    end
    if index == arr.size - 1
      final_string << count.to_s << " " << last_element << " "
    end
  end
  puts final_string[0..-2]
end

File.open(ARGV[0]).each_line do |line|
  if !line.empty?
    calculate(line)
  end
end