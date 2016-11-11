class Circle : public Drawable {
public:
  Circle(float x, float y, float rad)
    : Shape(x, y), rad{rad} {}
  void draw() const override {
    cout << "Circle: (" << x << ", " << y << ", " << rad << ")\n";
  }
private:
  float rad;
};
