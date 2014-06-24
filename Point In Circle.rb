REGEX_NUMBER = '(\-?\d+\.?\d*)'
REGEX_TWO_NUMBERS = "\\(#{REGEX_NUMBER}, #{REGEX_NUMBER}\\)"


class Point
	attr_accessor :x, :y

	def initialize(x, y)
		@x = x.to_f
		@y = y.to_f
	end
	
	def distanceTo(p)
		Math.sqrt((self.x - p.x) ** 2 + (self.y - p.y) ** 2)
	end
end


def inCircle?(line)
	line =~ /^Center: #{REGEX_TWO_NUMBERS}; Radius: #{REGEX_NUMBER}; Point: #{REGEX_TWO_NUMBERS}$/
	center = Point.new($1, $2)
	test_point = Point.new($4, $5)
	
	test_point.distanceTo(center) <= $3.to_f
end


File.open(ARGV[0]).each do |line|
	puts inCircle?(line)
end
