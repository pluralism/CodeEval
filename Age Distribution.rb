def calculate(line)
  int = line.to_i
  
  if(int < 0 || int > 100)
    "This program is for humans"
  elsif(int >= 66)
    "Retirement"
  elsif(int >= 23)
    "Work"
  elsif(int >= 19)
    "College"
  elsif(int >= 15)
    "High school"   
  elsif(int >= 12)
    "Middle school"
  elsif(int >= 5)
    "Elementary school"
  elsif(int >= 3)
    "Preschool"
  elsif(int >= 0)
    "Home"
  end 
end



File.open(ARGV[0]).each do |line|
  puts calculate(line)
end