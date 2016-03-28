class TyA{
public : 
  virtual void serialize(JSONOutputArchive& archive) const = 0;

};
class TyB{
public : 
  virtual void serialize(JSONOutputArchive& archive) const = 0;

};
class TyC{
public : 
  TyC(int _x, int _y);
  void serialize(JSONOutputArchive& archive) const;

private : 
  int x;
  int y;

};
class ConsB : public TyA{
public : 
  ConsB(std::unique_ptr<B> _b);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<B> b;

};
class ConsC : public TyB{
public : 
  ConsC(std::unique_ptr<C> _c);
  static std::unique_ptr<TyB> make(int _x, int _y) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<C> c;

};
