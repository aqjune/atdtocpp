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
  ConsC(std::shared_ptr<TyC> _c);
  static std::shared_ptr<TyB> make(int _x, int _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyC> c;
};

struct ConsB : public TyA{
public : 
  ConsB(std::shared_ptr<TyB> _b);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyB> b;
};

