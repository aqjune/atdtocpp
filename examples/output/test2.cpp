ConsHalfType::ConsHalfType(){
}
void ConsHalfType::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("HalfType");
}

ConsFloatType::ConsFloatType(){
}
void ConsFloatType::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("FloatType");
}

ConsDoubleType::ConsDoubleType(){
}
void ConsDoubleType::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("DoubleType");
}

ConsFP128Type::ConsFP128Type(){
}
void ConsFP128Type::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("FP128Type");
}

ConsPPCFP128Type::ConsPPCFP128Type(){
}
void ConsPPCFP128Type::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("PPC_FP128Type");
}

ConsX86FP80Type::ConsX86FP80Type(){
}
void ConsX86FP80Type::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("X86_FP80Type");
}

