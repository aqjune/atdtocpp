ConsD::ConsD(){
}
void ConsD::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("D");
}

ConsE::ConsE(){
}
void ConsE::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("E");
}

ConsF::ConsF(){
}
void ConsF::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("F");
}

ConsC::ConsC(std::shared_ptr<TyC> _c) : c(_c){
}
void ConsC::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("C");
  archive(CEREAL_NVP(c));
}

ConsB::ConsB(std::shared_ptr<TyB> _b) : b(_b){
}
void ConsB::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("B");
  archive(CEREAL_NVP(b));
}

