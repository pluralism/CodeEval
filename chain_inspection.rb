def evaluate_chain(chain)
	prev_val = 0
	next_val = chain["BEGIN"]
	chain.delete("BEGIN")
	# Special case: BEGIN - END
	return true if chain.empty?
	prev_val = next_val
	
	loop do
		next_val = chain[prev_val]
		return false if next_val.nil?
		chain.delete(prev_val)
		return true if chain.empty?
		prev_val = next_val
	end
end


def chain(line)
	line.delete!("\n")
	return false if !line.include?("BEGIN") or !line.include?("END")
	arr = line.split(';')
	
	vals = { }
	arr.each do |f|
		s = f.split('-')
		vals[s[0]] = s[1]
	end
	
	evaluate_chain(vals)
end


File.open(ARGV[0]).each do |line|
	if chain(line)
		puts "GOOD"
	else
		puts "BAD"
	end
end
