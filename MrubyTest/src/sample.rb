def setup
  @x = 0
end

def update
  @x += 5
  @x = 0 if @x >= 1024
end

def draw
  circle(@x     , 100, 30)
  circle(@x + 20, 200, 35)
  circle(@x + 40, 300, 40)
  circle(@x + 60, 400, 45)
end
