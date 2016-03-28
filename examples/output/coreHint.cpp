TyAddAssociative::TyAddAssociative(std::unique_ptr<Register> _x, std::unique_ptr<Register> _y, std::unique_ptr<Register> _z, std::unique_ptr<ConstInt> _c1, std::unique_ptr<ConstInt> _c2, std::unique_ptr<ConstInt> _c3, std::unique_ptr<Size> _sz) : x(std::move(_x)), y(std::move(_y)), z(std::move(_z)), c1(std::move(_c1)), c2(std::move(_c2)), c3(std::move(_c3)), sz(std::move(_sz)){
}
void TyAddAssociative::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(c1));
  archive(CEREAL_NVP(c2));
  archive(CEREAL_NVP(c3));
  archive(CEREAL_NVP(sz));
}

TyAddCommutative::TyAddCommutative(std::unique_ptr<Register> _z, std::unique_ptr<Value> _x, std::unique_ptr<Value> _y, std::unique_ptr<Size> _sz) : z(std::move(_z)), x(std::move(_x)), y(std::move(_y)), sz(std::move(_sz)){
}
void TyAddCommutative::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(sz));
}

TyAddConstNot::TyAddConstNot(std::unique_ptr<Register> _z, std::unique_ptr<Register> _y) : z(std::move(_z)), y(std::move(_y)){
}
void TyAddConstNot::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(y));
}

TyAddDistSub::TyAddDistSub(std::unique_ptr<Register> _z, std::unique_ptr<Register> _minusx, std::unique_ptr<Register> _minusy, std::unique_ptr<Register> _w) : z(std::move(_z)), minusx(std::move(_minusx)), minusy(std::move(_minusy)), w(std::move(_w)){
}
void TyAddDistSub::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(minusx));
  archive(CEREAL_NVP(minusy));
  archive(CEREAL_NVP(w));
}

TyAddMask::TyAddMask(std::unique_ptr<Register> _z, std::unique_ptr<Register> _y, std::unique_ptr<Register> _yp) : z(std::move(_z)), y(std::move(_y)), yp(std::move(_yp)){
}
void TyAddMask::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(yp));
}

TyAddOnebit::TyAddOnebit(std::unique_ptr<Register> _z, std::unique_ptr<Value> _x, std::unique_ptr<Value> _y) : z(std::move(_z)), x(std::move(_x)), y(std::move(_y)){
}
void TyAddOnebit::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
}

TyAddSelectZero::TyAddSelectZero(std::unique_ptr<Register> _z, std::unique_ptr<Register> _x, std::unique_ptr<Register> _y) : z(std::move(_z)), x(std::move(_x)), y(std::move(_y)){
}
void TyAddSelectZero::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
}

TyAddSelectZero2::TyAddSelectZero2(std::unique_ptr<Register> _z, std::unique_ptr<Register> _x, std::unique_ptr<Register> _y) : z(std::move(_z)), x(std::move(_x)), y(std::move(_y)){
}
void TyAddSelectZero2::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
}

TyAddShift::TyAddShift(std::unique_ptr<Register> _y, std::unique_ptr<Value> _v, std::unique_ptr<Size> _sz) : y(std::move(_y)), v(std::move(_v)), sz(std::move(_sz)){
}
void TyAddShift::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(v));
  archive(CEREAL_NVP(sz));
}

TyAddSignbit::TyAddSignbit(std::unique_ptr<Register> _x, std::unique_ptr<Value> _e1, std::unique_ptr<Value> _e2, std::unique_ptr<Size> _sz) : x(std::move(_x)), e1(std::move(_e1)), e2(std::move(_e2)), sz(std::move(_sz)){
}
void TyAddSignbit::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(e1));
  archive(CEREAL_NVP(e2));
  archive(CEREAL_NVP(sz));
}

TyAddSub::TyAddSub(std::unique_ptr<Register> _minusy, std::unique_ptr<Register> _z, std::unique_ptr<Value> _x, std::unique_ptr<Value> _y, std::unique_ptr<Size> _sz) : minusy(std::move(_minusy)), z(std::move(_z)), x(std::move(_x)), y(std::move(_y)), sz(std::move(_sz)){
}
void TyAddSub::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(minusy));
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(sz));
}

TyAddZextBool::TyAddZextBool(std::unique_ptr<Register> _x, std::unique_ptr<Register> _y, std::unique_ptr<Value> _b, std::unique_ptr<ConstInt> _c, std::unique_ptr<ConstInt> _c', std::unique_ptr<Size> _sz) : x(std::move(_x)), y(std::move(_y)), b(std::move(_b)), c(std::move(_c)), c'(std::move(_c')), sz(std::move(_sz)){
}
void TyAddZextBool::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(b));
  archive(CEREAL_NVP(c));
  archive(CEREAL_NVP(c'));
  archive(CEREAL_NVP(sz));
}

TyAndDeMorgan::TyAndDeMorgan(std::unique_ptr<Register> _z, std::unique_ptr<Register> _x, std::unique_ptr<Register> _y, std::unique_ptr<Register> _z2) : z(std::move(_z)), x(std::move(_x)), y(std::move(_y)), z2(std::move(_z2)){
}
void TyAndDeMorgan::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(z2));
}

TyConstFloat::TyConstFloat(double _float_value, std::unique_ptr<FloatType> _float_type) : float_value(std::move(_float_value)), float_type(std::move(_float_type)){
}
void TyConstFloat::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(float_value));
  archive(CEREAL_NVP(float_type));
}

TyConstInt::TyConstInt(int _int_value, std::unique_ptr<IntType> _int_type) : int_value(std::move(_int_value)), int_type(std::move(_int_type)){
}
void TyConstInt::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(int_value));
  archive(CEREAL_NVP(int_type));
}

TyDivMone::TyDivMone(std::unique_ptr<Register> _z) : z(std::move(_z)){
}
void TyDivMone::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
}

TyDivSubSrem::TyDivSubSrem(std::unique_ptr<Register> _z, std::unique_ptr<Register> _b, std::unique_ptr<Register> _a) : z(std::move(_z)), b(std::move(_b)), a(std::move(_a)){
}
void TyDivSubSrem::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(b));
  archive(CEREAL_NVP(a));
}

TyDivSubUrem::TyDivSubUrem(std::unique_ptr<Register> _z, std::unique_ptr<Register> _b, std::unique_ptr<Register> _a) : z(std::move(_z)), b(std::move(_b)), a(std::move(_a)){
}
void TyDivSubUrem::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(b));
  archive(CEREAL_NVP(a));
}

TyHints::TyHints(std::string _module_id, std::string _function_id, std::string _opt_name, std::vector<std::unique_ptr<NopPosition>> _src_nop_positions, std::vector<std::unique_ptr<NopPosition>> _tgt_nop_positions, std::vector<std::unique_ptr<Command>> _commands) : module_id(std::move(_module_id)), function_id(std::move(_function_id)), opt_name(std::move(_opt_name)), src_nop_positions(std::move(_src_nop_positions)), tgt_nop_positions(std::move(_tgt_nop_positions)), commands(std::move(_commands)){
}
void TyHints::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(module_id));
  archive(CEREAL_NVP(function_id));
  archive(CEREAL_NVP(opt_name));
  archive(CEREAL_NVP(src_nop_positions));
  archive(CEREAL_NVP(tgt_nop_positions));
  archive(CEREAL_NVP(commands));
}

TyMulAddDistributive::TyMulAddDistributive(std::unique_ptr<Register> _z, std::unique_ptr<Register> _x, std::unique_ptr<Register> _y, std::unique_ptr<Register> _w) : z(std::move(_z)), x(std::move(_x)), y(std::move(_y)), w(std::move(_w)){
}
void TyMulAddDistributive::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(w));
}

TyMulBool::TyMulBool(std::unique_ptr<Register> _z, std::unique_ptr<Register> _x, std::unique_ptr<Register> _y) : z(std::move(_z)), x(std::move(_x)), y(std::move(_y)){
}
void TyMulBool::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
}

TyMulCommutative::TyMulCommutative(std::unique_ptr<Register> _z) : z(std::move(_z)){
}
void TyMulCommutative::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
}

TyMulMone::TyMulMone(std::unique_ptr<Register> _z) : z(std::move(_z)){
}
void TyMulMone::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
}

TyMulNeg::TyMulNeg(std::unique_ptr<Register> _z, std::unique_ptr<Register> _mx, std::unique_ptr<Register> _my) : z(std::move(_z)), mx(std::move(_mx)), my(std::move(_my)){
}
void TyMulNeg::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(mx));
  archive(CEREAL_NVP(my));
}

TyMulShl::TyMulShl(std::unique_ptr<Register> _z, std::unique_ptr<Register> _y) : z(std::move(_z)), y(std::move(_y)){
}
void TyMulShl::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(y));
}

TyNegVal::TyNegVal(std::unique_ptr<ConstInt> _c1, std::unique_ptr<ConstInt> _c2, std::unique_ptr<Size> _sz) : c1(std::move(_c1)), c2(std::move(_c2)), sz(std::move(_sz)){
}
void TyNegVal::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(c1));
  archive(CEREAL_NVP(c2));
  archive(CEREAL_NVP(sz));
}

TyPositionCommand::TyPositionCommand(std::unique_ptr<Scope> _scope, std::string _register_name) : scope(std::move(_scope)), register_name(std::move(_register_name)){
}
void TyPositionCommand::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(scope));
  archive(CEREAL_NVP(register_name));
}

TyPositionPhinode::TyPositionPhinode(std::string _block_name, std::string _prev_block_name) : block_name(std::move(_block_name)), prev_block_name(std::move(_prev_block_name)){
}
void TyPositionPhinode::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(block_name));
  archive(CEREAL_NVP(prev_block_name));
}

TyPropagate::TyPropagate(std::unique_ptr<PropagateObject> _propagate, std::unique_ptr<PropagateRange> _propagate_range) : propagate(std::move(_propagate)), propagate_range(std::move(_propagate_range)){
}
void TyPropagate::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(propagate));
  archive(CEREAL_NVP(propagate_range));
}

TyPropagateLessdef::TyPropagateLessdef(std::unique_ptr<Expr> _lhs, std::unique_ptr<Expr> _rhs, std::unique_ptr<Scope> _scope) : lhs(std::move(_lhs)), rhs(std::move(_rhs)), scope(std::move(_scope)){
}
void TyPropagateLessdef::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(lhs));
  archive(CEREAL_NVP(rhs));
  archive(CEREAL_NVP(scope));
}

TyPropagateNoalias::TyPropagateNoalias(std::unique_ptr<Register> _lhs, std::unique_ptr<Register> _rhs, std::unique_ptr<Scope> _scope) : lhs(std::move(_lhs)), rhs(std::move(_rhs)), scope(std::move(_scope)){
}
void TyPropagateNoalias::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(lhs));
  archive(CEREAL_NVP(rhs));
  archive(CEREAL_NVP(scope));
}

TyRegister::TyRegister(std::string _name, std::unique_ptr<Tag> _tag) : name(std::move(_name)), tag(std::move(_tag)){
}
void TyRegister::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(name));
  archive(CEREAL_NVP(tag));
}

TyRemNeg::TyRemNeg(std::unique_ptr<Register> _z, std::unique_ptr<Register> _my) : z(std::move(_z)), my(std::move(_my)){
}
void TyRemNeg::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(my));
}

TySubAdd::TySubAdd(std::unique_ptr<Register> _z, std::unique_ptr<Value> _my, std::unique_ptr<Register> _x, std::unique_ptr<Value> _y, std::unique_ptr<Size> _sz) : z(std::move(_z)), my(std::move(_my)), x(std::move(_x)), y(std::move(_y)), sz(std::move(_sz)){
}
void TySubAdd::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(my));
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(sz));
}

TySubConstAdd::TySubConstAdd(std::unique_ptr<Register> _y, std::unique_ptr<Register> _z) : y(std::move(_y)), z(std::move(_z)){
}
void TySubConstAdd::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(z));
}

TySubConstNot::TySubConstNot(std::unique_ptr<Register> _y, std::unique_ptr<Register> _z) : y(std::move(_y)), z(std::move(_z)){
}
void TySubConstNot::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(z));
}

TySubMone::TySubMone(std::unique_ptr<Register> _z) : z(std::move(_z)){
}
void TySubMone::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
}

TySubOnebit::TySubOnebit(std::unique_ptr<Register> _z) : z(std::move(_z)){
}
void TySubOnebit::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
}

TySubRemove::TySubRemove(std::unique_ptr<Register> _z, std::unique_ptr<Register> _y, std::unique_ptr<Value> _a, std::unique_ptr<Value> _b, std::unique_ptr<Size> _sz) : z(std::move(_z)), y(std::move(_y)), a(std::move(_a)), b(std::move(_b)), sz(std::move(_sz)){
}
void TySubRemove::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(a));
  archive(CEREAL_NVP(b));
  archive(CEREAL_NVP(sz));
}

TySubRemove2::TySubRemove2(std::unique_ptr<Register> _y, std::unique_ptr<Register> _z) : y(std::move(_y)), z(std::move(_z)){
}
void TySubRemove2::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(z));
}

TySubSdiv::TySubSdiv(std::unique_ptr<Register> _y, std::unique_ptr<Register> _z) : y(std::move(_y)), z(std::move(_z)){
}
void TySubSdiv::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(z));
}

TySubShl::TySubShl(std::unique_ptr<Register> _x, std::unique_ptr<Register> _y, std::unique_ptr<Register> _z) : x(std::move(_x)), y(std::move(_y)), z(std::move(_z)){
}
void TySubShl::serialize(JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(z));
}

ConsPropagate::ConsPropagate(std::unique_ptr<Propagate> _propagate) : propagate(std::move(_propagate)){
}
std::unique_ptr<TyCommand> ConsPropagate::make(std::unique_ptr<PropagateObject> _propagate, std::unique_ptr<PropagateRange> _propagate_range) const{
  std::unique_ptr<TyPropagate> _val(new TyPropagate(std::move(_propagate), std::move(_propagate_range)));;
  return std::unique_ptr<TyCommand>(ConsPropagate(std::move(_val)));;
}
void ConsPropagate::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Propagate");
  archive(CEREAL_NVP(propagate));
}

ConsInfrule::ConsInfrule(std::unique_ptr<Position> _position, std::unique_ptr<Infrule> _infrule) : position(std::move(_position)), infrule(std::move(_infrule)){
}
void ConsInfrule::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Infrule");
  archive.startNode();
  archive.makeArray();
  archive(CEREAL_NVP(position));
  archive(CEREAL_NVP(infrule));
  archive.finishNode();
}

ConsConstInt::ConsConstInt(std::unique_ptr<ConstInt> _const_int) : const_int(std::move(_const_int)){
}
std::unique_ptr<TyConstant> ConsConstInt::make(int _int_value, std::unique_ptr<IntType> _int_type) const{
  std::unique_ptr<TyConstInt> _val(new TyConstInt(std::move(_int_value), std::move(_int_type)));;
  return std::unique_ptr<TyConstant>(ConsConstInt(std::move(_val)));;
}
void ConsConstInt::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("ConstInt");
  archive(CEREAL_NVP(const_int));
}

ConsConstFloat::ConsConstFloat(std::unique_ptr<ConstFloat> _const_float) : const_float(std::move(_const_float)){
}
std::unique_ptr<TyConstant> ConsConstFloat::make(double _float_value, std::unique_ptr<FloatType> _float_type) const{
  std::unique_ptr<TyConstFloat> _val(new TyConstFloat(std::move(_float_value), std::move(_float_type)));;
  return std::unique_ptr<TyConstant>(ConsConstFloat(std::move(_val)));;
}
void ConsConstFloat::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("ConstFloat");
  archive(CEREAL_NVP(const_float));
}

ConsVar::ConsVar(std::unique_ptr<Register> _register) : register(std::move(_register)){
}
std::unique_ptr<TyExpr> ConsVar::make(std::string _name, std::unique_ptr<Tag> _tag) const{
  std::unique_ptr<TyRegister> _val(new TyRegister(std::move(_name), std::move(_tag)));;
  return std::unique_ptr<TyExpr>(ConsVar(std::move(_val)));;
}
void ConsVar::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Var");
  archive(CEREAL_NVP(register));
}

ConsRhs::ConsRhs(std::unique_ptr<Register> _register, std::unique_ptr<Scope> _scope) : register(std::move(_register)), scope(std::move(_scope)){
}
void ConsRhs::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Rhs");
  archive.startNode();
  archive.makeArray();
  archive(CEREAL_NVP(register));
  archive(CEREAL_NVP(scope));
  archive.finishNode();
}

ConsConst::ConsConst(std::unique_ptr<Constant> _constant) : constant(std::move(_constant)){
}
void ConsConst::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Const");
  archive(CEREAL_NVP(constant));
}

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

ConsAddAssociative::ConsAddAssociative(std::unique_ptr<AddAssociative> _add_associative) : add_associative(std::move(_add_associative)){
}
std::unique_ptr<TyInfrule> ConsAddAssociative::make(std::unique_ptr<Register> _x, std::unique_ptr<Register> _y, std::unique_ptr<Register> _z, std::unique_ptr<ConstInt> _c1, std::unique_ptr<ConstInt> _c2, std::unique_ptr<ConstInt> _c3, std::unique_ptr<Size> _sz) const{
  std::unique_ptr<TyAddAssociative> _val(new TyAddAssociative(std::move(_x), std::move(_y), std::move(_z), std::move(_c1), std::move(_c2), std::move(_c3), std::move(_sz)));;
  return std::unique_ptr<TyInfrule>(ConsAddAssociative(std::move(_val)));;
}
void ConsAddAssociative::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddAssociative");
  archive(CEREAL_NVP(add_associative));
}

ConsAddSub::ConsAddSub(std::unique_ptr<AddSub> _add_sub) : add_sub(std::move(_add_sub)){
}
std::unique_ptr<TyInfrule> ConsAddSub::make(std::unique_ptr<Register> _minusy, std::unique_ptr<Register> _z, std::unique_ptr<Value> _x, std::unique_ptr<Value> _y, std::unique_ptr<Size> _sz) const{
  std::unique_ptr<TyAddSub> _val(new TyAddSub(std::move(_minusy), std::move(_z), std::move(_x), std::move(_y), std::move(_sz)));;
  return std::unique_ptr<TyInfrule>(ConsAddSub(std::move(_val)));;
}
void ConsAddSub::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddSub");
  archive(CEREAL_NVP(add_sub));
}

ConsAddCommutative::ConsAddCommutative(std::unique_ptr<AddCommutative> _add_commutative) : add_commutative(std::move(_add_commutative)){
}
std::unique_ptr<TyInfrule> ConsAddCommutative::make(std::unique_ptr<Register> _z, std::unique_ptr<Value> _x, std::unique_ptr<Value> _y, std::unique_ptr<Size> _sz) const{
  std::unique_ptr<TyAddCommutative> _val(new TyAddCommutative(std::move(_z), std::move(_x), std::move(_y), std::move(_sz)));;
  return std::unique_ptr<TyInfrule>(ConsAddCommutative(std::move(_val)));;
}
void ConsAddCommutative::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddCommutative");
  archive(CEREAL_NVP(add_commutative));
}

ConsAddShift::ConsAddShift(std::unique_ptr<AddShift> _add_shift) : add_shift(std::move(_add_shift)){
}
std::unique_ptr<TyInfrule> ConsAddShift::make(std::unique_ptr<Register> _y, std::unique_ptr<Value> _v, std::unique_ptr<Size> _sz) const{
  std::unique_ptr<TyAddShift> _val(new TyAddShift(std::move(_y), std::move(_v), std::move(_sz)));;
  return std::unique_ptr<TyInfrule>(ConsAddShift(std::move(_val)));;
}
void ConsAddShift::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddShift");
  archive(CEREAL_NVP(add_shift));
}

ConsAddSignbit::ConsAddSignbit(std::unique_ptr<AddSignbit> _add_signbit) : add_signbit(std::move(_add_signbit)){
}
std::unique_ptr<TyInfrule> ConsAddSignbit::make(std::unique_ptr<Register> _x, std::unique_ptr<Value> _e1, std::unique_ptr<Value> _e2, std::unique_ptr<Size> _sz) const{
  std::unique_ptr<TyAddSignbit> _val(new TyAddSignbit(std::move(_x), std::move(_e1), std::move(_e2), std::move(_sz)));;
  return std::unique_ptr<TyInfrule>(ConsAddSignbit(std::move(_val)));;
}
void ConsAddSignbit::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddSignbit");
  archive(CEREAL_NVP(add_signbit));
}

ConsAddOnebit::ConsAddOnebit(std::unique_ptr<AddOnebit> _add_onebit) : add_onebit(std::move(_add_onebit)){
}
std::unique_ptr<TyInfrule> ConsAddOnebit::make(std::unique_ptr<Register> _z, std::unique_ptr<Value> _x, std::unique_ptr<Value> _y) const{
  std::unique_ptr<TyAddOnebit> _val(new TyAddOnebit(std::move(_z), std::move(_x), std::move(_y)));;
  return std::unique_ptr<TyInfrule>(ConsAddOnebit(std::move(_val)));;
}
void ConsAddOnebit::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddOnebit");
  archive(CEREAL_NVP(add_onebit));
}

ConsAddZextBool::ConsAddZextBool(std::unique_ptr<AddZextBool> _add_zext_bool) : add_zext_bool(std::move(_add_zext_bool)){
}
std::unique_ptr<TyInfrule> ConsAddZextBool::make(std::unique_ptr<Register> _x, std::unique_ptr<Register> _y, std::unique_ptr<Value> _b, std::unique_ptr<ConstInt> _c, std::unique_ptr<ConstInt> _c', std::unique_ptr<Size> _sz) const{
  std::unique_ptr<TyAddZextBool> _val(new TyAddZextBool(std::move(_x), std::move(_y), std::move(_b), std::move(_c), std::move(_c'), std::move(_sz)));;
  return std::unique_ptr<TyInfrule>(ConsAddZextBool(std::move(_val)));;
}
void ConsAddZextBool::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddZextBool");
  archive(CEREAL_NVP(add_zext_bool));
}

ConsAddConstNot::ConsAddConstNot(std::unique_ptr<AddConstNot> _add_const_not) : add_const_not(std::move(_add_const_not)){
}
std::unique_ptr<TyInfrule> ConsAddConstNot::make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _y) const{
  std::unique_ptr<TyAddConstNot> _val(new TyAddConstNot(std::move(_z), std::move(_y)));;
  return std::unique_ptr<TyInfrule>(ConsAddConstNot(std::move(_val)));;
}
void ConsAddConstNot::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddConstNot");
  archive(CEREAL_NVP(add_const_not));
}

ConsAddMask::ConsAddMask(std::unique_ptr<AddMask> _add_mask) : add_mask(std::move(_add_mask)){
}
std::unique_ptr<TyInfrule> ConsAddMask::make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _y, std::unique_ptr<Register> _yp) const{
  std::unique_ptr<TyAddMask> _val(new TyAddMask(std::move(_z), std::move(_y), std::move(_yp)));;
  return std::unique_ptr<TyInfrule>(ConsAddMask(std::move(_val)));;
}
void ConsAddMask::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddMask");
  archive(CEREAL_NVP(add_mask));
}

ConsAddSelectZero::ConsAddSelectZero(std::unique_ptr<AddSelectZero> _add_select_zero) : add_select_zero(std::move(_add_select_zero)){
}
std::unique_ptr<TyInfrule> ConsAddSelectZero::make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _x, std::unique_ptr<Register> _y) const{
  std::unique_ptr<TyAddSelectZero> _val(new TyAddSelectZero(std::move(_z), std::move(_x), std::move(_y)));;
  return std::unique_ptr<TyInfrule>(ConsAddSelectZero(std::move(_val)));;
}
void ConsAddSelectZero::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddSelectZero");
  archive(CEREAL_NVP(add_select_zero));
}

ConsAddSelectZero2::ConsAddSelectZero2(std::unique_ptr<AddSelectZero2> _add_select_zero2) : add_select_zero2(std::move(_add_select_zero2)){
}
std::unique_ptr<TyInfrule> ConsAddSelectZero2::make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _x, std::unique_ptr<Register> _y) const{
  std::unique_ptr<TyAddSelectZero2> _val(new TyAddSelectZero2(std::move(_z), std::move(_x), std::move(_y)));;
  return std::unique_ptr<TyInfrule>(ConsAddSelectZero2(std::move(_val)));;
}
void ConsAddSelectZero2::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddSelectZero2");
  archive(CEREAL_NVP(add_select_zero2));
}

ConsAddDistSub::ConsAddDistSub(std::unique_ptr<AddDistSub> _add_dist_sub) : add_dist_sub(std::move(_add_dist_sub)){
}
std::unique_ptr<TyInfrule> ConsAddDistSub::make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _minusx, std::unique_ptr<Register> _minusy, std::unique_ptr<Register> _w) const{
  std::unique_ptr<TyAddDistSub> _val(new TyAddDistSub(std::move(_z), std::move(_minusx), std::move(_minusy), std::move(_w)));;
  return std::unique_ptr<TyInfrule>(ConsAddDistSub(std::move(_val)));;
}
void ConsAddDistSub::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddDistSub");
  archive(CEREAL_NVP(add_dist_sub));
}

ConsMulAddDistributive::ConsMulAddDistributive(std::unique_ptr<MulAddDistributive> _mul_add_distributive) : mul_add_distributive(std::move(_mul_add_distributive)){
}
std::unique_ptr<TyInfrule> ConsMulAddDistributive::make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _x, std::unique_ptr<Register> _y, std::unique_ptr<Register> _w) const{
  std::unique_ptr<TyMulAddDistributive> _val(new TyMulAddDistributive(std::move(_z), std::move(_x), std::move(_y), std::move(_w)));;
  return std::unique_ptr<TyInfrule>(ConsMulAddDistributive(std::move(_val)));;
}
void ConsMulAddDistributive::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("MulAddDistributive");
  archive(CEREAL_NVP(mul_add_distributive));
}

ConsSubMone::ConsSubMone(std::unique_ptr<SubMone> _sub_mone) : sub_mone(std::move(_sub_mone)){
}
std::unique_ptr<TyInfrule> ConsSubMone::make(std::unique_ptr<Register> _z) const{
  std::unique_ptr<TySubMone> _val(new TySubMone(std::move(_z)));;
  return std::unique_ptr<TyInfrule>(ConsSubMone(std::move(_val)));;
}
void ConsSubMone::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("SubMone");
  archive(CEREAL_NVP(sub_mone));
}

ConsSubAdd::ConsSubAdd(std::unique_ptr<SubAdd> _sub_add) : sub_add(std::move(_sub_add)){
}
std::unique_ptr<TyInfrule> ConsSubAdd::make(std::unique_ptr<Register> _z, std::unique_ptr<Value> _my, std::unique_ptr<Register> _x, std::unique_ptr<Value> _y, std::unique_ptr<Size> _sz) const{
  std::unique_ptr<TySubAdd> _val(new TySubAdd(std::move(_z), std::move(_my), std::move(_x), std::move(_y), std::move(_sz)));;
  return std::unique_ptr<TyInfrule>(ConsSubAdd(std::move(_val)));;
}
void ConsSubAdd::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("SubAdd");
  archive(CEREAL_NVP(sub_add));
}

ConsSubConstNot::ConsSubConstNot(std::unique_ptr<SubConstNot> _sub_const_not) : sub_const_not(std::move(_sub_const_not)){
}
std::unique_ptr<TyInfrule> ConsSubConstNot::make(std::unique_ptr<Register> _y, std::unique_ptr<Register> _z) const{
  std::unique_ptr<TySubConstNot> _val(new TySubConstNot(std::move(_y), std::move(_z)));;
  return std::unique_ptr<TyInfrule>(ConsSubConstNot(std::move(_val)));;
}
void ConsSubConstNot::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("SubConstNot");
  archive(CEREAL_NVP(sub_const_not));
}

ConsSubRemove::ConsSubRemove(std::unique_ptr<SubRemove> _sub_remove) : sub_remove(std::move(_sub_remove)){
}
std::unique_ptr<TyInfrule> ConsSubRemove::make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _y, std::unique_ptr<Value> _a, std::unique_ptr<Value> _b, std::unique_ptr<Size> _sz) const{
  std::unique_ptr<TySubRemove> _val(new TySubRemove(std::move(_z), std::move(_y), std::move(_a), std::move(_b), std::move(_sz)));;
  return std::unique_ptr<TyInfrule>(ConsSubRemove(std::move(_val)));;
}
void ConsSubRemove::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("SubRemove");
  archive(CEREAL_NVP(sub_remove));
}

ConsSubRemove2::ConsSubRemove2(std::unique_ptr<SubRemove2> _sub_remove2) : sub_remove2(std::move(_sub_remove2)){
}
std::unique_ptr<TyInfrule> ConsSubRemove2::make(std::unique_ptr<Register> _y, std::unique_ptr<Register> _z) const{
  std::unique_ptr<TySubRemove2> _val(new TySubRemove2(std::move(_y), std::move(_z)));;
  return std::unique_ptr<TyInfrule>(ConsSubRemove2(std::move(_val)));;
}
void ConsSubRemove2::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("SubRemove2");
  archive(CEREAL_NVP(sub_remove2));
}

ConsSubOnebit::ConsSubOnebit(std::unique_ptr<SubOnebit> _sub_onebit) : sub_onebit(std::move(_sub_onebit)){
}
std::unique_ptr<TyInfrule> ConsSubOnebit::make(std::unique_ptr<Register> _z) const{
  std::unique_ptr<TySubOnebit> _val(new TySubOnebit(std::move(_z)));;
  return std::unique_ptr<TyInfrule>(ConsSubOnebit(std::move(_val)));;
}
void ConsSubOnebit::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("SubOnebit");
  archive(CEREAL_NVP(sub_onebit));
}

ConsSubConstAdd::ConsSubConstAdd(std::unique_ptr<SubConstAdd> _sub_const_add) : sub_const_add(std::move(_sub_const_add)){
}
std::unique_ptr<TyInfrule> ConsSubConstAdd::make(std::unique_ptr<Register> _y, std::unique_ptr<Register> _z) const{
  std::unique_ptr<TySubConstAdd> _val(new TySubConstAdd(std::move(_y), std::move(_z)));;
  return std::unique_ptr<TyInfrule>(ConsSubConstAdd(std::move(_val)));;
}
void ConsSubConstAdd::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("SubConstAdd");
  archive(CEREAL_NVP(sub_const_add));
}

ConsSubSdiv::ConsSubSdiv(std::unique_ptr<SubSdiv> _sub_sdiv) : sub_sdiv(std::move(_sub_sdiv)){
}
std::unique_ptr<TyInfrule> ConsSubSdiv::make(std::unique_ptr<Register> _y, std::unique_ptr<Register> _z) const{
  std::unique_ptr<TySubSdiv> _val(new TySubSdiv(std::move(_y), std::move(_z)));;
  return std::unique_ptr<TyInfrule>(ConsSubSdiv(std::move(_val)));;
}
void ConsSubSdiv::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("SubSdiv");
  archive(CEREAL_NVP(sub_sdiv));
}

ConsSubShl::ConsSubShl(std::unique_ptr<SubShl> _sub_shl) : sub_shl(std::move(_sub_shl)){
}
std::unique_ptr<TyInfrule> ConsSubShl::make(std::unique_ptr<Register> _x, std::unique_ptr<Register> _y, std::unique_ptr<Register> _z) const{
  std::unique_ptr<TySubShl> _val(new TySubShl(std::move(_x), std::move(_y), std::move(_z)));;
  return std::unique_ptr<TyInfrule>(ConsSubShl(std::move(_val)));;
}
void ConsSubShl::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("SubShl");
  archive(CEREAL_NVP(sub_shl));
}

ConsMulBool::ConsMulBool(std::unique_ptr<MulBool> _mul_bool) : mul_bool(std::move(_mul_bool)){
}
std::unique_ptr<TyInfrule> ConsMulBool::make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _x, std::unique_ptr<Register> _y) const{
  std::unique_ptr<TyMulBool> _val(new TyMulBool(std::move(_z), std::move(_x), std::move(_y)));;
  return std::unique_ptr<TyInfrule>(ConsMulBool(std::move(_val)));;
}
void ConsMulBool::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("MulBool");
  archive(CEREAL_NVP(mul_bool));
}

ConsMulMone::ConsMulMone(std::unique_ptr<MulMone> _mul_mone) : mul_mone(std::move(_mul_mone)){
}
std::unique_ptr<TyInfrule> ConsMulMone::make(std::unique_ptr<Register> _z) const{
  std::unique_ptr<TyMulMone> _val(new TyMulMone(std::move(_z)));;
  return std::unique_ptr<TyInfrule>(ConsMulMone(std::move(_val)));;
}
void ConsMulMone::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("MulMone");
  archive(CEREAL_NVP(mul_mone));
}

ConsMulNeg::ConsMulNeg(std::unique_ptr<MulNeg> _mul_neg) : mul_neg(std::move(_mul_neg)){
}
std::unique_ptr<TyInfrule> ConsMulNeg::make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _mx, std::unique_ptr<Register> _my) const{
  std::unique_ptr<TyMulNeg> _val(new TyMulNeg(std::move(_z), std::move(_mx), std::move(_my)));;
  return std::unique_ptr<TyInfrule>(ConsMulNeg(std::move(_val)));;
}
void ConsMulNeg::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("MulNeg");
  archive(CEREAL_NVP(mul_neg));
}

ConsMulCommutative::ConsMulCommutative(std::unique_ptr<MulCommutative> _mul_commutative) : mul_commutative(std::move(_mul_commutative)){
}
std::unique_ptr<TyInfrule> ConsMulCommutative::make(std::unique_ptr<Register> _z) const{
  std::unique_ptr<TyMulCommutative> _val(new TyMulCommutative(std::move(_z)));;
  return std::unique_ptr<TyInfrule>(ConsMulCommutative(std::move(_val)));;
}
void ConsMulCommutative::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("MulCommutative");
  archive(CEREAL_NVP(mul_commutative));
}

ConsMulShl::ConsMulShl(std::unique_ptr<MulShl> _mul_shl) : mul_shl(std::move(_mul_shl)){
}
std::unique_ptr<TyInfrule> ConsMulShl::make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _y) const{
  std::unique_ptr<TyMulShl> _val(new TyMulShl(std::move(_z), std::move(_y)));;
  return std::unique_ptr<TyInfrule>(ConsMulShl(std::move(_val)));;
}
void ConsMulShl::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("MulShl");
  archive(CEREAL_NVP(mul_shl));
}

ConsDivMone::ConsDivMone(std::unique_ptr<DivMone> _div_mone) : div_mone(std::move(_div_mone)){
}
std::unique_ptr<TyInfrule> ConsDivMone::make(std::unique_ptr<Register> _z) const{
  std::unique_ptr<TyDivMone> _val(new TyDivMone(std::move(_z)));;
  return std::unique_ptr<TyInfrule>(ConsDivMone(std::move(_val)));;
}
void ConsDivMone::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("DivMone");
  archive(CEREAL_NVP(div_mone));
}

ConsRemNeg::ConsRemNeg(std::unique_ptr<RemNeg> _rem_neg) : rem_neg(std::move(_rem_neg)){
}
std::unique_ptr<TyInfrule> ConsRemNeg::make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _my) const{
  std::unique_ptr<TyRemNeg> _val(new TyRemNeg(std::move(_z), std::move(_my)));;
  return std::unique_ptr<TyInfrule>(ConsRemNeg(std::move(_val)));;
}
void ConsRemNeg::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("RemNeg");
  archive(CEREAL_NVP(rem_neg));
}

ConsDivSubSrem::ConsDivSubSrem(std::unique_ptr<DivSubSrem> _div_sub_srem) : div_sub_srem(std::move(_div_sub_srem)){
}
std::unique_ptr<TyInfrule> ConsDivSubSrem::make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _b, std::unique_ptr<Register> _a) const{
  std::unique_ptr<TyDivSubSrem> _val(new TyDivSubSrem(std::move(_z), std::move(_b), std::move(_a)));;
  return std::unique_ptr<TyInfrule>(ConsDivSubSrem(std::move(_val)));;
}
void ConsDivSubSrem::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("DivSubSrem");
  archive(CEREAL_NVP(div_sub_srem));
}

ConsDivSubUrem::ConsDivSubUrem(std::unique_ptr<DivSubUrem> _div_sub_urem) : div_sub_urem(std::move(_div_sub_urem)){
}
std::unique_ptr<TyInfrule> ConsDivSubUrem::make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _b, std::unique_ptr<Register> _a) const{
  std::unique_ptr<TyDivSubUrem> _val(new TyDivSubUrem(std::move(_z), std::move(_b), std::move(_a)));;
  return std::unique_ptr<TyInfrule>(ConsDivSubUrem(std::move(_val)));;
}
void ConsDivSubUrem::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("DivSubUrem");
  archive(CEREAL_NVP(div_sub_urem));
}

ConsAndDeMorgan::ConsAndDeMorgan(std::unique_ptr<AndDeMorgan> _and_de_morgan) : and_de_morgan(std::move(_and_de_morgan)){
}
std::unique_ptr<TyInfrule> ConsAndDeMorgan::make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _x, std::unique_ptr<Register> _y, std::unique_ptr<Register> _z2) const{
  std::unique_ptr<TyAndDeMorgan> _val(new TyAndDeMorgan(std::move(_z), std::move(_x), std::move(_y), std::move(_z2)));;
  return std::unique_ptr<TyInfrule>(ConsAndDeMorgan(std::move(_val)));;
}
void ConsAndDeMorgan::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AndDeMorgan");
  archive(CEREAL_NVP(and_de_morgan));
}

ConsNegVal::ConsNegVal(std::unique_ptr<NegVal> _neg_val) : neg_val(std::move(_neg_val)){
}
std::unique_ptr<TyInfrule> ConsNegVal::make(std::unique_ptr<ConstInt> _c1, std::unique_ptr<ConstInt> _c2, std::unique_ptr<Size> _sz) const{
  std::unique_ptr<TyNegVal> _val(new TyNegVal(std::move(_c1), std::move(_c2), std::move(_sz)));;
  return std::unique_ptr<TyInfrule>(ConsNegVal(std::move(_val)));;
}
void ConsNegVal::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("NegVal");
  archive(CEREAL_NVP(neg_val));
}

ConsIntType::ConsIntType(int _i) : i(std::move(_i)){
}
void ConsIntType::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("IntType");
  archive(CEREAL_NVP(i));
}

ConsPhinodeCurrentBlockName::ConsPhinodeCurrentBlockName(std::string _s) : s(std::move(_s)){
}
void ConsPhinodeCurrentBlockName::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("PhinodeCurrentBlockName");
  archive(CEREAL_NVP(s));
}

ConsCommandRegisterName::ConsCommandRegisterName(std::string _s) : s(std::move(_s)){
}
void ConsCommandRegisterName::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("CommandRegisterName");
  archive(CEREAL_NVP(s));
}

ConsPhinode::ConsPhinode(std::unique_ptr<PositionPhinode> _position_phinode) : position_phinode(std::move(_position_phinode)){
}
std::unique_ptr<TyPosition> ConsPhinode::make(std::string _block_name, std::string _prev_block_name) const{
  std::unique_ptr<TyPositionPhinode> _val(new TyPositionPhinode(std::move(_block_name), std::move(_prev_block_name)));;
  return std::unique_ptr<TyPosition>(ConsPhinode(std::move(_val)));;
}
void ConsPhinode::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Phinode");
  archive(CEREAL_NVP(position_phinode));
}

ConsCommand::ConsCommand(std::unique_ptr<PositionCommand> _position_command) : position_command(std::move(_position_command)){
}
std::unique_ptr<TyPosition> ConsCommand::make(std::unique_ptr<Scope> _scope, std::string _register_name) const{
  std::unique_ptr<TyPositionCommand> _val(new TyPositionCommand(std::move(_scope), std::move(_register_name)));;
  return std::unique_ptr<TyPosition>(ConsCommand(std::move(_val)));;
}
void ConsCommand::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Command");
  archive(CEREAL_NVP(position_command));
}

ConsLessdef::ConsLessdef(std::unique_ptr<PropagateLessdef> _propagate_lessdef) : propagate_lessdef(std::move(_propagate_lessdef)){
}
std::unique_ptr<TyPropagateObject> ConsLessdef::make(std::unique_ptr<Expr> _lhs, std::unique_ptr<Expr> _rhs, std::unique_ptr<Scope> _scope) const{
  std::unique_ptr<TyPropagateLessdef> _val(new TyPropagateLessdef(std::move(_lhs), std::move(_rhs), std::move(_scope)));;
  return std::unique_ptr<TyPropagateObject>(ConsLessdef(std::move(_val)));;
}
void ConsLessdef::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Lessdef");
  archive(CEREAL_NVP(propagate_lessdef));
}

ConsNoalias::ConsNoalias(std::unique_ptr<PropagateNoalias> _propagate_noalias) : propagate_noalias(std::move(_propagate_noalias)){
}
std::unique_ptr<TyPropagateObject> ConsNoalias::make(std::unique_ptr<Register> _lhs, std::unique_ptr<Register> _rhs, std::unique_ptr<Scope> _scope) const{
  std::unique_ptr<TyPropagateNoalias> _val(new TyPropagateNoalias(std::move(_lhs), std::move(_rhs), std::move(_scope)));;
  return std::unique_ptr<TyPropagateObject>(ConsNoalias(std::move(_val)));;
}
void ConsNoalias::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Noalias");
  archive(CEREAL_NVP(propagate_noalias));
}

ConsMaydiff::ConsMaydiff(std::unique_ptr<Register> _register) : register(std::move(_register)){
}
std::unique_ptr<TyPropagateObject> ConsMaydiff::make(std::string _name, std::unique_ptr<Tag> _tag) const{
  std::unique_ptr<TyRegister> _val(new TyRegister(std::move(_name), std::move(_tag)));;
  return std::unique_ptr<TyPropagateObject>(ConsMaydiff(std::move(_val)));;
}
void ConsMaydiff::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Maydiff");
  archive(CEREAL_NVP(register));
}

ConsBounds::ConsBounds(std::unique_ptr<Position> _position, std::unique_ptr<Position> _position) : position(std::move(_position)), position(std::move(_position)){
}
void ConsBounds::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Bounds");
  archive.startNode();
  archive.makeArray();
  archive(CEREAL_NVP(position));
  archive(CEREAL_NVP(position));
  archive.finishNode();
}

ConsGlobal::ConsGlobal(){
}
void ConsGlobal::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Global");
}

ConsSource::ConsSource(){
}
void ConsSource::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Source");
}

ConsTarget::ConsTarget(){
}
void ConsTarget::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Target");
}

ConsSize::ConsSize(int _i) : i(std::move(_i)){
}
void ConsSize::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Size");
  archive(CEREAL_NVP(i));
}

ConsPhysical::ConsPhysical(){
}
void ConsPhysical::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Physical");
}

ConsPrevious::ConsPrevious(){
}
void ConsPrevious::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Previous");
}

ConsGhost::ConsGhost(){
}
void ConsGhost::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Ghost");
}

ConsId::ConsId(std::unique_ptr<Register> _register) : register(std::move(_register)){
}
std::unique_ptr<TyValue> ConsId::make(std::string _name, std::unique_ptr<Tag> _tag) const{
  std::unique_ptr<TyRegister> _val(new TyRegister(std::move(_name), std::move(_tag)));;
  return std::unique_ptr<TyValue>(ConsId(std::move(_val)));;
}
void ConsId::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Id");
  archive(CEREAL_NVP(register));
}

ConsConstVal::ConsConstVal(std::unique_ptr<Constant> _constant) : constant(std::move(_constant)){
}
void ConsConstVal::serialize(JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("ConstVal");
  archive(CEREAL_NVP(constant));
}

