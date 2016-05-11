TyConstFloat::TyConstFloat(double _float_value, std::shared_ptr<TyFloatType> _float_type) : float_value(_float_value), float_type(_float_type){
}
void TyConstFloat::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(float_value));
  archive(CEREAL_NVP(float_type));
}

TyConstInt::TyConstInt(int _int_value, std::shared_ptr<TyIntType> _int_type) : int_value(_int_value), int_type(_int_type){
}
void TyConstInt::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(int_value));
  archive(CEREAL_NVP(int_type));
}

ConsConstFloat::ConsConstFloat(std::shared_ptr<TyConstFloat> _const_float) : const_float(_const_float){
}
std::shared_ptr<TyConstant> ConsConstFloat::make(double _float_value, std::shared_ptr<TyFloatType> _float_type){
  std::shared_ptr<TyConstFloat> _val(new TyConstFloat(_float_value, _float_type));
  return std::shared_ptr<TyConstant>(new ConsConstFloat(_val));
}
void ConsConstFloat::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("ConstFloat");
  archive(CEREAL_NVP(const_float));
}

ConsConstInt::ConsConstInt(std::shared_ptr<TyConstInt> _const_int) : const_int(_const_int){
}
std::shared_ptr<TyConstant> ConsConstInt::make(int _int_value, std::shared_ptr<TyIntType> _int_type){
  std::shared_ptr<TyConstInt> _val(new TyConstInt(_int_value, _int_type));
  return std::shared_ptr<TyConstant>(new ConsConstInt(_val));
}
void ConsConstInt::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("ConstInt");
  archive(CEREAL_NVP(const_int));
}

ConsDoubleType::ConsDoubleType(){
}
void ConsDoubleType::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("DoubleType");
}

ConsFP128Type::ConsFP128Type(){
}
void ConsFP128Type::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("FP128Type");
}

ConsFloatType::ConsFloatType(){
}
void ConsFloatType::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("FloatType");
}

ConsHalfType::ConsHalfType(){
}
void ConsHalfType::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("HalfType");
}

ConsIntType::ConsIntType(int _i) : i(_i){
}
void ConsIntType::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("IntType");
  archive(CEREAL_NVP(i));
}

ConsPPCFP128Type::ConsPPCFP128Type(){
}
void ConsPPCFP128Type::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("PPC_FP128Type");
}

ConsX86FP80Type::ConsX86FP80Type(){
}
void ConsX86FP80Type::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("X86_FP80Type");
}

