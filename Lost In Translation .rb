def convert_to_human s
	dictionary = {
		'a' => 'y',
		'b' => 'h',
		'c' => 'e',
		'd' => 's',
		'e' => 'o',
		'f' => 'c',
		'g' => 'v',
		'h' => 'x',
		'i' => 'd',
		'j' => 'u',
		'k' => 'i',
		'l' => 'g',
		'm' => 'l',
		'n' => 'b',
		'o' => 'k',
		'p' => 'r',
		'q' => 'z',
		'r' => 't',
		's' => 'n',
		't' => 'w',
		'u' => 'j',
		'v' => 'p',
		'w' => 'f',
		'x' => 'm',
		'y' => 'a',
		'z' => 'q'
	}
	
	for i in 0...s.length
		if s[i] != ' ' && !dictionary[s[i]].nil?
			s[i] = dictionary[s[i]]
		end
	end
	puts s
end


File.open(ARGV[0]).each do |line|
	convert_to_human line
end
