TyAddAssociative::TyAddAssociative(std::unique_ptr<TyRegister> _x, std::unique_ptr<TyRegister> _y, std::unique_ptr<TyRegister> _z, std::unique_ptr<TyConstInt> _c1, std::unique_ptr<TyConstInt> _c2, std::unique_ptr<TyConstInt> _c3, std::unique_ptr<TySize> _sz) : x(std::move(_x)), y(std::move(_y)), z(std::move(_z)), c1(std::move(_c1)), c2(std::move(_c2)), c3(std::move(_c3)), sz(std::move(_sz)){
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

TyPositionCommand::TyPositionCommand(std::unique_ptr<TyScope> _scope, std::string _register_name) : scope(std::move(_scope)), register_name(std::move(_register_name)){
}
void TyPositionCommand::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(scope));
  archive(CEREAL_NVP(register_name));
}

TyPositionPhinode::TyPositionPhinode(std::string _block_name, std::string _prev_block_name) : block_name(std::move(_block_name)), prev_block_name(std::move(_prev_block_name)){
}
void TyPositionPhinode::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(block_name));
  archive(CEREAL_NVP(prev_block_name));
}

TyRegister::TyRegister(std::string _name, std::unique_ptr<TyTag> _tag) : name(std::move(_name)), tag(std::move(_tag)){
}
void TyRegister::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(name));
  archive(CEREAL_NVP(tag));
}

TyTransitivityPointerLhs::TyTransitivityPointerLhs(std::unique_ptr<TyValue> _p, std::unique_ptr<TyValue> _q, std::unique_ptr<TyValue> _v, std::unique_ptr<TyExpr> _loadq) : p(std::move(_p)), q(std::move(_q)), v(std::move(_v)), loadq(std::move(_loadq)){
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

ConsIntType::ConsIntType(int _i) : i(std::move(_i)){
}
void ConsIntType::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("IntType");
  archive(CEREAL_NVP(i));
}

ConsSize::ConsSize(int _i) : i(std::move(_i)){
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

ConsVar::ConsVar(std::unique_ptr<TyRegister> _register) : register(std::move(_register)){
}
std::unique_ptr<TyExpr> ConsVar::make(std::string _name, std::unique_ptr<TyTag> _tag){
  std::unique_ptr<TyRegister> _val(new TyRegister(std::move(_name), std::move(_tag)));
  return std::unique_ptr<TyExpr>(new ConsVar(std::move(_val)));
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

ConsRhs::ConsRhs(std::unique_ptr<TyRegister> _register, std::unique_ptr<TyScope> _scope) : register(std::move(_register)), scope(std::move(_scope)){
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

ConsConst::ConsConst(std::unique_ptr<TyConstant> _constant) : constant(std::move(_constant)){
}
void ConsConst::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Const");
  archive(CEREAL_NVP(constant));
}

ConsAddAssociative::ConsAddAssociative(std::unique_ptr<TyAddAssociative> _add_associative) : add_associative(std::move(_add_associative)){
}
std::unique_ptr<TyInfrule> ConsAddAssociative::make(std::unique_ptr<TyRegister> _x, std::unique_ptr<TyRegister> _y, std::unique_ptr<TyRegister> _z, std::unique_ptr<TyConstInt> _c1, std::unique_ptr<TyConstInt> _c2, std::unique_ptr<TyConstInt> _c3, std::unique_ptr<TySize> _sz){
  std::unique_ptr<TyAddAssociative> _val(new TyAddAssociative(std::move(_x), std::move(_y), std::move(_z), std::move(_c1), std::move(_c2), std::move(_c3), std::move(_sz)));
  return std::unique_ptr<TyInfrule>(new ConsAddAssociative(std::move(_val)));
}
void ConsAddAssociative::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddAssociative");
  archive(CEREAL_NVP(add_associative));
}

ConsId::ConsId(std::unique_ptr<TyRegister> _register) : register(std::move(_register)){
}
std::unique_ptr<TyValue> ConsId::make(std::string _name, std::unique_ptr<TyTag> _tag){
  std::unique_ptr<TyRegister> _val(new TyRegister(std::move(_name), std::move(_tag)));
  return std::unique_ptr<TyValue>(new ConsId(std::move(_val)));
}
void ConsId::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Id");
  archive(CEREAL_NVP(register));
}

ConsConstVal::ConsConstVal(std::unique_ptr<TyConstant> _constant) : constant(std::move(_constant)){
}
void ConsConstVal::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("ConstVal");
  archive(CEREAL_NVP(constant));
}

ConsTransitivityPointersLhs::ConsTransitivityPointersLhs(std::unique_ptr<TyTransitivityPointerLhs> _transitivity_pointer_lhs) : transitivity_pointer_lhs(std::move(_transitivity_pointer_lhs)){
}
std::unique_ptr<TyInfrule> ConsTransitivityPointersLhs::make(std::unique_ptr<TyValue> _p, std::unique_ptr<TyValue> _q, std::unique_ptr<TyValue> _v, std::unique_ptr<TyExpr> _loadq){
  std::unique_ptr<TyTransitivityPointerLhs> _val(new TyTransitivityPointerLhs(std::move(_p), std::move(_q), std::move(_v), std::move(_loadq)));
  return std::unique_ptr<TyInfrule>(new ConsTransitivityPointersLhs(std::move(_val)));
}
void ConsTransitivityPointersLhs::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("TransitivityPointersLhs");
  archive(CEREAL_NVP(transitivity_pointer_lhs));
}

ConsPhinode::ConsPhinode(std::unique_ptr<TyPositionPhinode> _position_phinode) : position_phinode(std::move(_position_phinode)){
}
std::unique_ptr<TyPosition> ConsPhinode::make(std::string _block_name, std::string _prev_block_name){
  std::unique_ptr<TyPositionPhinode> _val(new TyPositionPhinode(std::move(_block_name), std::move(_prev_block_name)));
  return std::unique_ptr<TyPosition>(new ConsPhinode(std::move(_val)));
}
void ConsPhinode::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Phinode");
  archive(CEREAL_NVP(position_phinode));
}

ConsCommand::ConsCommand(std::unique_ptr<TyPositionCommand> _position_command) : position_command(std::move(_position_command)){
}
std::unique_ptr<TyPosition> ConsCommand::make(std::unique_ptr<TyScope> _scope, std::string _register_name){
  std::unique_ptr<TyPositionCommand> _val(new TyPositionCommand(std::move(_scope), std::move(_register_name)));
  return std::unique_ptr<TyPosition>(new ConsCommand(std::move(_val)));
}
void ConsCommand::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Command");
  archive(CEREAL_NVP(position_command));
}

