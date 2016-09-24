
class Vector3D {

  private:

    float c[3];

  public:

    Vector3D(); 
    Vector3D(const Vector3D& v); 
    Vector3D(float x, float y, float z); 
    void setCoordinate(int i, float val);
    float getCoordinate(int i) const;
    float magnitude() const;
    void normalize();
    void absoluteValue(); // makes value positive
    Vector3D operator+(Vector3D& other); // vector sum
    float operator*(Vector3D& other); // dot product
};
