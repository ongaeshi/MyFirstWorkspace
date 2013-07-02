def setup
  puts "Hello ruby"
  p "Hello ruby"
  # p "Hello mruby"
  @x = 400
  @speed = 10
end

def update
  @x += @speed

  if @x > 1024
    @x = 0
  elsif @x < 0
    @x = 1024 
  end
end

def draw
  set_color(0, 0, 0)
  text("#{get_frame_rate} fps", 10, 15)
  text(<<EOF, 40, 40)
speed       : #{@speed}
mouse left  : speed up
mouse right : speed down
EOF

  set_color(255, 0, 0)
  circle(@x, 100, 30)

  set_color(0, 255, 0)
  circle(@x + 20, 200, 35)

  set_color(0, 0, 255)
  circle(@x + 40, 300, 40)

  c = (@x * 0.7) % 255
  set_color(c, c, c)
  circle(@x + 60, 400, 45)
end

def mouse_pressed(x, y, button)
  @speed += 5 if (button == 0)
  @speed -= 5 if (button == 2)  
end


# class Circle
#   def initialize(x, y)
#     @x = x
#     @y = y

#     Input.mousex
#     Input.mousey
#     Input.dragged
        
#   end
# end
