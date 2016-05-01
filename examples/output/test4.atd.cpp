TyAddAssociative::TyAddAssociative(std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z, std::shared_ptr<TyConstInt> _c1, std::shared_ptr<TyConstInt> _c2, std::shared_ptr<TyConstInt> _c3, std::shared_ptr<TySize> _sz) : x(_x), y(_y), z(_z), c1(_c1), c2(_c2), c3(_c3), sz(_sz){
}
void TyAddAssociative::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(c1));
  archive(CEREAL_NVP(c2));
  archive(CEREAL_NVP(c3));
  archive(CEREAL_NVP(sz));
}

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

TyPositionCommand::TyPositionCommand(std::shared_ptr<TyScope> _scope, std::string _register_name) : scope(_scope), register_name(_register_name){
}
void TyPositionCommand::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(scope));
  archive(CEREAL_NVP(register_name));
}

TyPositionPhinode::TyPositionPhinode(std::string _block_name, std::string _prev_block_name) : block_name(_block_name), prev_block_name(_prev_block_name){
}
void TyPositionPhinode::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(block_name));
  archive(CEREAL_NVP(prev_block_name));
}

TyRegister::TyRegister(std::string _name, std::shared_ptr<TyTag> _tag) : name(_name), tag(_tag){
}
void TyRegister::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(name));
  archive(CEREAL_NVP(tag));
}

TyTransitivityPointerLhs::TyTransitivityPointerLhs(std::shared_ptr<TyValue> _p, std::shared_ptr<TyValue> _q, std::shared_ptr<TyValue> _v, std::shared_ptr<TyExpr> _loadq) : p(_p), q(_q), v(_v), loadq(_loadq){
}
void TyTransitivityPointerLhs::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(p));
  archive(CEREAL_NVP(q));
  archive(CEREAL_NVP(v));
  archive(CEREAL_NVP(loadq));
}

ConsPhysical::ConsPhysical(){
}
void ConsPhysical::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Physical");
}

ConsPrevious::ConsPrevious(){
}
void ConsPrevious::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Previous");
}

ConsGhost::ConsGhost(){
}
void ConsGhost::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Ghost");
}

ConsIntType::ConsIntType(int _i) : i(_i){
}
void ConsIntType::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("IntType");
  archive(CEREAL_NVP(i));
}

ConsSize::ConsSize(int _i) : i(_i){
}
void ConsSize::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Size");
  archive(CEREAL_NVP(i));
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

ConsVar::ConsVar(std::shared_ptr<TyRegister> _register) : register(_register){
}
std::shared_ptr<TyExpr> ConsVar::make(std::string _name, std::shared_ptr<TyTag> _tag){
  std::shared_ptr<TyRegister> _val(new TyRegister(_name, _tag));
  return std::shared_ptr<TyExpr>(new ConsVar(_val));
}
void ConsVar::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Var");
  archive(CEREAL_NVP(register));
}

ConsSource::ConsSource(){
}
void ConsSource::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Source");
}

ConsTarget::ConsTarget(){
}
void ConsTarget::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Target");
}

ConsRhs::ConsRhs(std::shared_ptr<TyRegister> _register, std::shared_ptr<TyScope> _scope) : register(_register), scope(_scope){
}
void ConsRhs::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Rhs");
  archive.startNode();
  archive.makeArray();
  archive(CEREAL_NVP(register));
  archive(CEREAL_NVP(scope));
  archive.finishNode();
}

ConsConst::ConsConst(std::shared_ptr<TyConstant> _constant) : constant(_constant){
}
void ConsConst::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Const");
  archive(CEREAL_NVP(constant));
}

ConsAddAssociative::ConsAddAssociative(std::shared_ptr<TyAddAssociative> _add_associative) : add_associative(_add_associative){
}
std::shared_ptr<TyInfrule> ConsAddAssociative::make(std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z, std::shared_ptr<TyConstInt> _c1, std::shared_ptr<TyConstInt> _c2, std::shared_ptr<TyConstInt> _c3, std::shared_ptr<TySize> _sz){
  std::shared_ptr<TyAddAssociative> _val(new TyAddAssociative(_x, _y, _z, _c1, _c2, _c3, _sz));
  return std::shared_ptr<TyInfrule>(new ConsAddAssociative(_val));
}
void ConsAddAssociative::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddAssociative");
  archive(CEREAL_NVP(add_associative));
}

ConsId::ConsId(std::shared_ptr<TyRegister> _register) : register(_register){
}
std::shared_ptr<TyValue> ConsId::make(std::string _name, std::shared_ptr<TyTag> _tag){
  std::shared_ptr<TyRegister> _val(new TyRegister(_name, _tag));
  return std::shared_ptr<TyValue>(new ConsId(_val));
}
void ConsId::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Id");
  archive(CEREAL_NVP(register));
}

ConsConstVal::ConsConstVal(std::shared_ptr<TyConstant> _constant) : constant(_constant){
}
void ConsConstVal::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("ConstVal");
  archive(CEREAL_NVP(constant));
}

ConsTransitivityPointersLhs::ConsTransitivityPointersLhs(std::shared_ptr<TyTransitivityPointerLhs> _transitivity_pointer_lhs) : transitivity_pointer_lhs(_transitivity_pointer_lhs){
}
std::shared_ptr<TyInfrule> ConsTransitivityPointersLhs::make(std::shared_ptr<TyValue> _p, std::shared_ptr<TyValue> _q, std::shared_ptr<TyValue> _v, std::shared_ptr<TyExpr> _loadq){
  std::shared_ptr<TyTransitivityPointerLhs> _val(new TyTransitivityPointerLhs(_p, _q, _v, _loadq));
  return std::shared_ptr<TyInfrule>(new ConsTransitivityPointersLhs(_val));
}
void ConsTransitivityPointersLhs::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("TransitivityPointersLhs");
  archive(CEREAL_NVP(transitivity_pointer_lhs));
}

ConsPhinode::ConsPhinode(std::shared_ptr<TyPositionPhinode> _position_phinode) : position_phinode(_position_phinode){
}
std::shared_ptr<TyPosition> ConsPhinode::make(std::string _block_name, std::string _prev_block_name){
  std::shared_ptr<TyPositionPhinode> _val(new TyPositionPhinode(_block_name, _prev_block_name));
  return std::shared_ptr<TyPosition>(new ConsPhinode(_val));
}
void ConsPhinode::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Phinode");
  archive(CEREAL_NVP(position_phinode));
}

ConsCommand::ConsCommand(std::shared_ptr<TyPositionCommand> _position_command) : position_command(_position_command){
}
std::shared_ptr<TyPosition> ConsCommand::make(std::shared_ptr<TyScope> _scope, std::string _register_name){
  std::shared_ptr<TyPositionCommand> _val(new TyPositionCommand(_scope, _register_name));
  return std::shared_ptr<TyPosition>(new ConsCommand(_val));
}
void ConsCommand::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Command");
  archive(CEREAL_NVP(position_command));
}

