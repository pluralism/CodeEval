def calculate_binary(arr)
  i = 0
  binary_string = ""
  options = { "00" => "1", "0" => "0" }
  
  until i >= arr.length
    for j in 0...arr[i + 1].size
      binary_string << options[arr[i]]
    end
    i += 2
  end

  puts binary_string.to_i(2)
end


File.open(ARGV[0]).each do |line|
  calculate_binary(line.split)
end