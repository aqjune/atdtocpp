TyC::TyC(int _x, int _y) : x(std::move(_x)), y(std::move(_y)){
}
void TyC::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
}

ConsC::ConsC(std::unique_ptr<TyC> _c) : c(std::move(_c)){
}
std::unique_ptr<TyB> ConsC::make(int _x, int _y){
  std::unique_ptr<TyC> _val(new TyC(std::move(_x), std::move(_y)));
  return std::unique_ptr<TyB>(new ConsC(std::move(_val)));
}
void ConsC::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("C");
  archive(CEREAL_NVP(c));
}

ConsB::ConsB(std::unique_ptr<TyB> _b) : b(std::move(_b)){
}
void ConsB::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("B");
  archive(CEREAL_NVP(b));
}

