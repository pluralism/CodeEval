File.open(ARGV[0]).each_line do |line|
  arr = line.split('|').map(&:strip)
  map = arr.map { |n| n.split("") }
  count = 0
  for i in 0...map.length - 1
    for j in 0...map[0].length - 1
      letters = [
        map[i][j],
        map[i][j + 1],
        map[i + 1][j],
        map[i + 1][j + 1]
      ]
      count += 1 if letters.sort.join == "cdeo"
    end
  end
  puts count
end
