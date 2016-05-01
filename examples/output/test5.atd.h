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
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};

struct ConsD : public TyC{
public : 
  ConsD();
  void serialize(cereal::JSONOutputArchive& archive) const;
};

struct ConsE : public TyC{
public : 
  ConsE();
  void serialize(cereal::JSONOutputArchive& archive) const;
};

struct ConsF : public TyC{
public : 
  ConsF();
  void serialize(cereal::JSONOutputArchive& archive) const;
};

struct ConsC : public TyB{
public : 
  ConsC(std::shared_ptr<TyC> _c);
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

