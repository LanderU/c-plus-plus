class Triangulo{
  private:
    double _resultado;
  public:
    Triangulo(){};
    double calculo(double l, double a){
      _resultado = (l*a)/2;
      return _resultado;
    }
};
