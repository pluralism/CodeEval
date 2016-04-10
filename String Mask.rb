File.open(ARGV[0]).each_line do |line|
    arr = line.split
    
    final = arr[0].split("")
    final.map!.with_index do |c, index|
	    if arr[1][index].eql? '1'
    		c.upcase
    	else
		    c.downcase
		end
	end
	puts final.join
end
