TyC::TyC(int _x, int _y) : x(std::move(_x)), y(std::move(_y)){
}
void TyC::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
}

ConsB::ConsB(std::unique_ptr<B> _b) : b(std::move(_b)){
}
void ConsB::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("B");
  archive(CEREAL_NVP(b));
}

ConsC::ConsC(std::unique_ptr<C> _c) : c(std::move(_c)){
}
std::unique_ptr<TyB> ConsC::make(int _x, int _y) const{
  std::unique_ptr<TyC> _val(new TyC(std::move(_x), std::move(_y)));;
  return std::unique_ptr<TyB>(ConsC(std::move(_val)));;
}
void ConsC::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("C");
  archive(CEREAL_NVP(c));
}

