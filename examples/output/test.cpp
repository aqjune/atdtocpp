TyConstFloat::TyConstFloat(double _float_value, std::unique_ptr<TyFloatType> _float_type) : float_value(std::move(_float_value)), float_type(std::move(_float_type)){
}
void TyConstFloat::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(float_value));
  archive(CEREAL_NVP(float_type));
}

TyConstInt::TyConstInt(int _int_value, std::unique_ptr<TyIntType> _int_type) : int_value(std::move(_int_value)), int_type(std::move(_int_type)){
}
void TyConstInt::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(int_value));
  archive(CEREAL_NVP(int_type));
}

ConsHalfType::ConsHalfType(){
}
void ConsHalfType::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("HalfType");
}

ConsFloatType::ConsFloatType(){
}
void ConsFloatType::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("FloatType");
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

ConsIntType::ConsIntType(int _i) : i(std::move(_i)){
}
void ConsIntType::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("IntType");
  archive(CEREAL_NVP(i));
}

ConsConstInt::ConsConstInt(std::unique_ptr<TyConstInt> _const_int) : const_int(std::move(_const_int)){
}
std::unique_ptr<TyConstant> ConsConstInt::make(int _int_value, std::unique_ptr<TyIntType> _int_type){
  std::unique_ptr<TyConstInt> _val(new TyConstInt(std::move(_int_value), std::move(_int_type)));
  return std::unique_ptr<TyConstant>(new ConsConstInt(std::move(_val)));
}
void ConsConstInt::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("ConstInt");
  archive(CEREAL_NVP(const_int));
}

ConsConstFloat::ConsConstFloat(std::unique_ptr<TyConstFloat> _const_float) : const_float(std::move(_const_float)){
}
std::unique_ptr<TyConstant> ConsConstFloat::make(double _float_value, std::unique_ptr<TyFloatType> _float_type){
  std::unique_ptr<TyConstFloat> _val(new TyConstFloat(std::move(_float_value), std::move(_float_type)));
  return std::unique_ptr<TyConstant>(new ConsConstFloat(std::move(_val)));
}
void ConsConstFloat::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("ConstFloat");
  archive(CEREAL_NVP(const_float));
}

