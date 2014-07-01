track = Array.new


def update_track(track, fIndex, start, last_index)
  if fIndex < last_index
    track[start][fIndex] = '/'
  elsif fIndex == last_index
    track[start][fIndex] = '|'
  elsif fIndex > last_index
    track[start][fIndex] = '\\'
  end
end

def calculate(track)
  start = 1
  last_index = 0
  # Try to find the gate in the first line
  fIndex = track[0].index('_')
  track[0][fIndex] = '|'
  last_index = fIndex
  while start < track.size
    # Try to find a checkpoint first
    fIndex = track[start].index('C')
    # We found a checkpoint
    if !fIndex.nil?
      update_track(track, fIndex, start, last_index)
    else
      # Try to find a gate
      fIndex = track[start].index('_')
      if !fIndex.nil?
        update_track(track, fIndex, start, last_index)
      end
    end
    last_index = fIndex
    start += 1
  end
  puts track.join
end

File.open(ARGV[0]).each_line do |line|
  a = Array.new
  line.each_char do |f|
    a << f
  end
  track << a
end

calculate(track)