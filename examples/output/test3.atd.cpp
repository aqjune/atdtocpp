TyC::TyC(int _x, int _y) : x(_x), y(_y){
}
void TyC::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
}

ConsB::ConsB(std::shared_ptr<TyB> _b) : b(_b){
}
void ConsB::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("B");
  archive(CEREAL_NVP(b));
}

ConsC::ConsC(std::shared_ptr<TyC> _c) : c(_c){
}
std::shared_ptr<TyB> ConsC::make(int _x, int _y){
  std::shared_ptr<TyC> _val(new TyC(_x, _y));
  return std::shared_ptr<TyB>(new ConsC(_val));
}
void ConsC::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("C");
  archive(CEREAL_NVP(c));
}

