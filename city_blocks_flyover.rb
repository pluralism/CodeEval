class Brick 
	attr_accessor :xi, :xf, :yi, :yf	
	
	def initialize(xi, xf, yi, yf)
		@xi = xi
		@xf = xf
		@yi = yi
		@yf = yf
	end
end


def flyover(line)
	first_index = line.index('(')
	last_index = line.index(')')
	substring = line[first_index + 1...last_index]
	
	# The first_arr Array represents the x-axis
	first_arr = substring.split(',')
	
	first_index = line.index('(', first_index + 1)
	last_index = line.index(')', last_index + 1)
	substring = line[first_index + 1...last_index]
	
	# The second_arr Array represents the y-axis
	second_arr = substring.split(',')
	
	
	# Calculate the line slope
	slope = (second_arr[second_arr.length - 1].to_f - second_arr[0].to_f) / (first_arr[first_arr.length - 1].to_f - first_arr[0].to_f)
	
	

	bricks = Array.new
	# At this point we need to create an Array of Brick objects
	for i in 1...(second_arr.length)
		for j in 1...(first_arr.length)
			bricks.push(Brick.new(first_arr[j - 1].to_f, first_arr[j].to_f, second_arr[i - 1].to_f, second_arr[i].to_f))
		end
	end
	
	# At this point we have all the bricks from the image in a single Array of Brick objects
	total_bricks = 0
	
	
	bricks.each do |brick|
		if(brick.xi * slope < brick.yf and brick.xf * slope > brick.yi)
			total_bricks = total_bricks + 1
		end
	end
	
	puts total_bricks
end


File.open(ARGV[0]).each do |line|
	flyover(line)
end
