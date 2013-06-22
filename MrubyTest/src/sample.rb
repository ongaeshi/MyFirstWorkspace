def setup
  @x = 0
end

def update
  @x += 5
  @x = 0 if @x >= 1024
end

def draw
  set_color(255, 0, 0)
  circle(@x     , 100, 30)

  set_color(0, 255, 0)
  circle(@x + 20, 200, 35)

  set_color(0, 0, 255)
  circle(@x + 40, 300, 40)

  set_color(128, @x % 255, 0)
  circle(@x + 60, 400, 45)
end
