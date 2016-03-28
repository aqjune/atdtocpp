struct TyA{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};
struct TyB{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};
struct TyC{
public : 
  TyC(int _x, int _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  int x;
  int y;
};
struct ConsC : public TyB{
public : 
  ConsC(std::unique_ptr<TyC> _c);
  static std::unique_ptr<TyB> make(int _x, int _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyC> c;
};
struct ConsB : public TyA{
public : 
  ConsB(std::unique_ptr<TyB> _b);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyB> b;
};
