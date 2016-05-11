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

TyAddCommutative::TyAddCommutative(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyValue> _x, std::shared_ptr<TyValue> _y, std::shared_ptr<TySize> _sz) : z(_z), x(_x), y(_y), sz(_sz){
}
void TyAddCommutative::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(sz));
}

TyAddConstNot::TyAddConstNot(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _y) : z(_z), y(_y){
}
void TyAddConstNot::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(y));
}

TyAddDistSub::TyAddDistSub(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _minusx, std::shared_ptr<TyRegister> _minusy, std::shared_ptr<TyRegister> _w) : z(_z), minusx(_minusx), minusy(_minusy), w(_w){
}
void TyAddDistSub::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(minusx));
  archive(CEREAL_NVP(minusy));
  archive(CEREAL_NVP(w));
}

TyAddMask::TyAddMask(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _yp) : z(_z), y(_y), yp(_yp){
}
void TyAddMask::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(yp));
}

TyAddOnebit::TyAddOnebit(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyValue> _x, std::shared_ptr<TyValue> _y) : z(_z), x(_x), y(_y){
}
void TyAddOnebit::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
}

TyAddSelectZero::TyAddSelectZero(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y) : z(_z), x(_x), y(_y){
}
void TyAddSelectZero::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
}

TyAddSelectZero2::TyAddSelectZero2(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y) : z(_z), x(_x), y(_y){
}
void TyAddSelectZero2::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
}

TyAddShift::TyAddShift(std::shared_ptr<TyRegister> _y, std::shared_ptr<TyValue> _v, std::shared_ptr<TySize> _sz) : y(_y), v(_v), sz(_sz){
}
void TyAddShift::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(v));
  archive(CEREAL_NVP(sz));
}

TyAddSignbit::TyAddSignbit(std::shared_ptr<TyRegister> _x, std::shared_ptr<TyValue> _e1, std::shared_ptr<TyValue> _e2, std::shared_ptr<TySize> _sz) : x(_x), e1(_e1), e2(_e2), sz(_sz){
}
void TyAddSignbit::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(e1));
  archive(CEREAL_NVP(e2));
  archive(CEREAL_NVP(sz));
}

TyAddSub::TyAddSub(std::shared_ptr<TyRegister> _minusy, std::shared_ptr<TyRegister> _z, std::shared_ptr<TyValue> _x, std::shared_ptr<TyValue> _y, std::shared_ptr<TySize> _sz) : minusy(_minusy), z(_z), x(_x), y(_y), sz(_sz){
}
void TyAddSub::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(minusy));
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(sz));
}

TyAddZextBool::TyAddZextBool(std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyValue> _b, std::shared_ptr<TyConstInt> _c, std::shared_ptr<TyConstInt> _cprime, std::shared_ptr<TySize> _sz) : x(_x), y(_y), b(_b), c(_c), cprime(_cprime), sz(_sz){
}
void TyAddZextBool::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(b));
  archive(CEREAL_NVP(c));
  archive(CEREAL_NVP(cprime));
  archive(CEREAL_NVP(sz));
}

TyAndDeMorgan::TyAndDeMorgan(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z2) : z(_z), x(_x), y(_y), z2(_z2){
}
void TyAndDeMorgan::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(z2));
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

TyDivMone::TyDivMone(std::shared_ptr<TyRegister> _z) : z(_z){
}
void TyDivMone::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
}

TyDivSubSrem::TyDivSubSrem(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _b, std::shared_ptr<TyRegister> _a) : z(_z), b(_b), a(_a){
}
void TyDivSubSrem::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(b));
  archive(CEREAL_NVP(a));
}

TyDivSubUrem::TyDivSubUrem(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _b, std::shared_ptr<TyRegister> _a) : z(_z), b(_b), a(_a){
}
void TyDivSubUrem::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(b));
  archive(CEREAL_NVP(a));
}

TyHints::TyHints(std::string _module_id, std::string _function_id, std::string _opt_name, std::vector<std::shared_ptr<TyNopPosition>> _src_nop_positions, std::vector<std::shared_ptr<TyNopPosition>> _tgt_nop_positions, std::vector<std::shared_ptr<TyCommand>> _commands) : module_id(_module_id), function_id(_function_id), opt_name(_opt_name), src_nop_positions(_src_nop_positions), tgt_nop_positions(_tgt_nop_positions), commands(_commands){
}
void TyHints::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(module_id));
  archive(CEREAL_NVP(function_id));
  archive(CEREAL_NVP(opt_name));
  archive(CEREAL_NVP(src_nop_positions));
  archive(CEREAL_NVP(tgt_nop_positions));
  archive(CEREAL_NVP(commands));
}

TyMulAddDistributive::TyMulAddDistributive(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _w) : z(_z), x(_x), y(_y), w(_w){
}
void TyMulAddDistributive::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(w));
}

TyMulBool::TyMulBool(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y) : z(_z), x(_x), y(_y){
}
void TyMulBool::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
}

TyMulCommutative::TyMulCommutative(std::shared_ptr<TyRegister> _z) : z(_z){
}
void TyMulCommutative::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
}

TyMulMone::TyMulMone(std::shared_ptr<TyRegister> _z) : z(_z){
}
void TyMulMone::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
}

TyMulNeg::TyMulNeg(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _mx, std::shared_ptr<TyRegister> _my) : z(_z), mx(_mx), my(_my){
}
void TyMulNeg::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(mx));
  archive(CEREAL_NVP(my));
}

TyMulShl::TyMulShl(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _y) : z(_z), y(_y){
}
void TyMulShl::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(y));
}

TyNegVal::TyNegVal(std::shared_ptr<TyConstInt> _c1, std::shared_ptr<TyConstInt> _c2, std::shared_ptr<TySize> _sz) : c1(_c1), c2(_c2), sz(_sz){
}
void TyNegVal::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(c1));
  archive(CEREAL_NVP(c2));
  archive(CEREAL_NVP(sz));
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

TyPropagate::TyPropagate(std::shared_ptr<TyPropagateObject> _propagate, std::shared_ptr<TyPropagateRange> _propagate_range) : propagate(_propagate), propagate_range(_propagate_range){
}
void TyPropagate::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(propagate));
  archive(CEREAL_NVP(propagate_range));
}

TyPropagateLessdef::TyPropagateLessdef(std::shared_ptr<TyExpr> _lhs, std::shared_ptr<TyExpr> _rhs, std::shared_ptr<TyScope> _scope) : lhs(_lhs), rhs(_rhs), scope(_scope){
}
void TyPropagateLessdef::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(lhs));
  archive(CEREAL_NVP(rhs));
  archive(CEREAL_NVP(scope));
}

TyPropagateNoalias::TyPropagateNoalias(std::shared_ptr<TyRegister> _lhs, std::shared_ptr<TyRegister> _rhs, std::shared_ptr<TyScope> _scope) : lhs(_lhs), rhs(_rhs), scope(_scope){
}
void TyPropagateNoalias::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(lhs));
  archive(CEREAL_NVP(rhs));
  archive(CEREAL_NVP(scope));
}

TyRegister::TyRegister(std::string _name, std::shared_ptr<TyTag> _tag) : name(_name), tag(_tag){
}
void TyRegister::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(name));
  archive(CEREAL_NVP(tag));
}

TyRemNeg::TyRemNeg(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _my) : z(_z), my(_my){
}
void TyRemNeg::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(my));
}

TySubAdd::TySubAdd(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyValue> _my, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyValue> _y, std::shared_ptr<TySize> _sz) : z(_z), my(_my), x(_x), y(_y), sz(_sz){
}
void TySubAdd::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(my));
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(sz));
}

TySubConstAdd::TySubConstAdd(std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z) : y(_y), z(_z){
}
void TySubConstAdd::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(z));
}

TySubConstNot::TySubConstNot(std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z) : y(_y), z(_z){
}
void TySubConstNot::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(z));
}

TySubMone::TySubMone(std::shared_ptr<TyRegister> _z) : z(_z){
}
void TySubMone::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
}

TySubOnebit::TySubOnebit(std::shared_ptr<TyRegister> _z) : z(_z){
}
void TySubOnebit::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
}

TySubRemove::TySubRemove(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyValue> _a, std::shared_ptr<TyValue> _b, std::shared_ptr<TySize> _sz) : z(_z), y(_y), a(_a), b(_b), sz(_sz){
}
void TySubRemove::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(z));
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(a));
  archive(CEREAL_NVP(b));
  archive(CEREAL_NVP(sz));
}

TySubRemove2::TySubRemove2(std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z) : y(_y), z(_z){
}
void TySubRemove2::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(z));
}

TySubSdiv::TySubSdiv(std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z) : y(_y), z(_z){
}
void TySubSdiv::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(z));
}

TySubShl::TySubShl(std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z) : x(_x), y(_y), z(_z){
}
void TySubShl::serialize(cereal::JSONOutputArchive& archive) const{
  archive(CEREAL_NVP(x));
  archive(CEREAL_NVP(y));
  archive(CEREAL_NVP(z));
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

ConsAddCommutative::ConsAddCommutative(std::shared_ptr<TyAddCommutative> _add_commutative) : add_commutative(_add_commutative){
}
std::shared_ptr<TyInfrule> ConsAddCommutative::make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyValue> _x, std::shared_ptr<TyValue> _y, std::shared_ptr<TySize> _sz){
  std::shared_ptr<TyAddCommutative> _val(new TyAddCommutative(_z, _x, _y, _sz));
  return std::shared_ptr<TyInfrule>(new ConsAddCommutative(_val));
}
void ConsAddCommutative::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddCommutative");
  archive(CEREAL_NVP(add_commutative));
}

ConsAddConstNot::ConsAddConstNot(std::shared_ptr<TyAddConstNot> _add_const_not) : add_const_not(_add_const_not){
}
std::shared_ptr<TyInfrule> ConsAddConstNot::make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _y){
  std::shared_ptr<TyAddConstNot> _val(new TyAddConstNot(_z, _y));
  return std::shared_ptr<TyInfrule>(new ConsAddConstNot(_val));
}
void ConsAddConstNot::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddConstNot");
  archive(CEREAL_NVP(add_const_not));
}

ConsAddDistSub::ConsAddDistSub(std::shared_ptr<TyAddDistSub> _add_dist_sub) : add_dist_sub(_add_dist_sub){
}
std::shared_ptr<TyInfrule> ConsAddDistSub::make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _minusx, std::shared_ptr<TyRegister> _minusy, std::shared_ptr<TyRegister> _w){
  std::shared_ptr<TyAddDistSub> _val(new TyAddDistSub(_z, _minusx, _minusy, _w));
  return std::shared_ptr<TyInfrule>(new ConsAddDistSub(_val));
}
void ConsAddDistSub::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddDistSub");
  archive(CEREAL_NVP(add_dist_sub));
}

ConsAddMask::ConsAddMask(std::shared_ptr<TyAddMask> _add_mask) : add_mask(_add_mask){
}
std::shared_ptr<TyInfrule> ConsAddMask::make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _yp){
  std::shared_ptr<TyAddMask> _val(new TyAddMask(_z, _y, _yp));
  return std::shared_ptr<TyInfrule>(new ConsAddMask(_val));
}
void ConsAddMask::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddMask");
  archive(CEREAL_NVP(add_mask));
}

ConsAddOnebit::ConsAddOnebit(std::shared_ptr<TyAddOnebit> _add_onebit) : add_onebit(_add_onebit){
}
std::shared_ptr<TyInfrule> ConsAddOnebit::make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyValue> _x, std::shared_ptr<TyValue> _y){
  std::shared_ptr<TyAddOnebit> _val(new TyAddOnebit(_z, _x, _y));
  return std::shared_ptr<TyInfrule>(new ConsAddOnebit(_val));
}
void ConsAddOnebit::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddOnebit");
  archive(CEREAL_NVP(add_onebit));
}

ConsAddSelectZero::ConsAddSelectZero(std::shared_ptr<TyAddSelectZero> _add_select_zero) : add_select_zero(_add_select_zero){
}
std::shared_ptr<TyInfrule> ConsAddSelectZero::make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y){
  std::shared_ptr<TyAddSelectZero> _val(new TyAddSelectZero(_z, _x, _y));
  return std::shared_ptr<TyInfrule>(new ConsAddSelectZero(_val));
}
void ConsAddSelectZero::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddSelectZero");
  archive(CEREAL_NVP(add_select_zero));
}

ConsAddSelectZero2::ConsAddSelectZero2(std::shared_ptr<TyAddSelectZero2> _add_select_zero2) : add_select_zero2(_add_select_zero2){
}
std::shared_ptr<TyInfrule> ConsAddSelectZero2::make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y){
  std::shared_ptr<TyAddSelectZero2> _val(new TyAddSelectZero2(_z, _x, _y));
  return std::shared_ptr<TyInfrule>(new ConsAddSelectZero2(_val));
}
void ConsAddSelectZero2::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddSelectZero2");
  archive(CEREAL_NVP(add_select_zero2));
}

ConsAddShift::ConsAddShift(std::shared_ptr<TyAddShift> _add_shift) : add_shift(_add_shift){
}
std::shared_ptr<TyInfrule> ConsAddShift::make(std::shared_ptr<TyRegister> _y, std::shared_ptr<TyValue> _v, std::shared_ptr<TySize> _sz){
  std::shared_ptr<TyAddShift> _val(new TyAddShift(_y, _v, _sz));
  return std::shared_ptr<TyInfrule>(new ConsAddShift(_val));
}
void ConsAddShift::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddShift");
  archive(CEREAL_NVP(add_shift));
}

ConsAddSignbit::ConsAddSignbit(std::shared_ptr<TyAddSignbit> _add_signbit) : add_signbit(_add_signbit){
}
std::shared_ptr<TyInfrule> ConsAddSignbit::make(std::shared_ptr<TyRegister> _x, std::shared_ptr<TyValue> _e1, std::shared_ptr<TyValue> _e2, std::shared_ptr<TySize> _sz){
  std::shared_ptr<TyAddSignbit> _val(new TyAddSignbit(_x, _e1, _e2, _sz));
  return std::shared_ptr<TyInfrule>(new ConsAddSignbit(_val));
}
void ConsAddSignbit::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddSignbit");
  archive(CEREAL_NVP(add_signbit));
}

ConsAddSub::ConsAddSub(std::shared_ptr<TyAddSub> _add_sub) : add_sub(_add_sub){
}
std::shared_ptr<TyInfrule> ConsAddSub::make(std::shared_ptr<TyRegister> _minusy, std::shared_ptr<TyRegister> _z, std::shared_ptr<TyValue> _x, std::shared_ptr<TyValue> _y, std::shared_ptr<TySize> _sz){
  std::shared_ptr<TyAddSub> _val(new TyAddSub(_minusy, _z, _x, _y, _sz));
  return std::shared_ptr<TyInfrule>(new ConsAddSub(_val));
}
void ConsAddSub::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddSub");
  archive(CEREAL_NVP(add_sub));
}

ConsAddZextBool::ConsAddZextBool(std::shared_ptr<TyAddZextBool> _add_zext_bool) : add_zext_bool(_add_zext_bool){
}
std::shared_ptr<TyInfrule> ConsAddZextBool::make(std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyValue> _b, std::shared_ptr<TyConstInt> _c, std::shared_ptr<TyConstInt> _cprime, std::shared_ptr<TySize> _sz){
  std::shared_ptr<TyAddZextBool> _val(new TyAddZextBool(_x, _y, _b, _c, _cprime, _sz));
  return std::shared_ptr<TyInfrule>(new ConsAddZextBool(_val));
}
void ConsAddZextBool::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AddZextBool");
  archive(CEREAL_NVP(add_zext_bool));
}

ConsAndDeMorgan::ConsAndDeMorgan(std::shared_ptr<TyAndDeMorgan> _and_de_morgan) : and_de_morgan(_and_de_morgan){
}
std::shared_ptr<TyInfrule> ConsAndDeMorgan::make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z2){
  std::shared_ptr<TyAndDeMorgan> _val(new TyAndDeMorgan(_z, _x, _y, _z2));
  return std::shared_ptr<TyInfrule>(new ConsAndDeMorgan(_val));
}
void ConsAndDeMorgan::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("AndDeMorgan");
  archive(CEREAL_NVP(and_de_morgan));
}

ConsBounds::ConsBounds(std::shared_ptr<TyPosition> _position, std::shared_ptr<TyPosition> _position) : position(_position), position(_position){
}
void ConsBounds::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Bounds");
  archive.startNode();
  archive.makeArray();
  archive(CEREAL_NVP(position));
  archive(CEREAL_NVP(position));
  archive.finishNode();
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

ConsCommandRegisterName::ConsCommandRegisterName(std::string _s) : s(_s){
}
void ConsCommandRegisterName::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("CommandRegisterName");
  archive(CEREAL_NVP(s));
}

ConsConst::ConsConst(std::shared_ptr<TyConstant> _constant) : constant(_constant){
}
void ConsConst::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Const");
  archive(CEREAL_NVP(constant));
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

ConsConstVal::ConsConstVal(std::shared_ptr<TyConstant> _constant) : constant(_constant){
}
void ConsConstVal::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("ConstVal");
  archive(CEREAL_NVP(constant));
}

ConsDivMone::ConsDivMone(std::shared_ptr<TyDivMone> _div_mone) : div_mone(_div_mone){
}
std::shared_ptr<TyInfrule> ConsDivMone::make(std::shared_ptr<TyRegister> _z){
  std::shared_ptr<TyDivMone> _val(new TyDivMone(_z));
  return std::shared_ptr<TyInfrule>(new ConsDivMone(_val));
}
void ConsDivMone::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("DivMone");
  archive(CEREAL_NVP(div_mone));
}

ConsDivSubSrem::ConsDivSubSrem(std::shared_ptr<TyDivSubSrem> _div_sub_srem) : div_sub_srem(_div_sub_srem){
}
std::shared_ptr<TyInfrule> ConsDivSubSrem::make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _b, std::shared_ptr<TyRegister> _a){
  std::shared_ptr<TyDivSubSrem> _val(new TyDivSubSrem(_z, _b, _a));
  return std::shared_ptr<TyInfrule>(new ConsDivSubSrem(_val));
}
void ConsDivSubSrem::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("DivSubSrem");
  archive(CEREAL_NVP(div_sub_srem));
}

ConsDivSubUrem::ConsDivSubUrem(std::shared_ptr<TyDivSubUrem> _div_sub_urem) : div_sub_urem(_div_sub_urem){
}
std::shared_ptr<TyInfrule> ConsDivSubUrem::make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _b, std::shared_ptr<TyRegister> _a){
  std::shared_ptr<TyDivSubUrem> _val(new TyDivSubUrem(_z, _b, _a));
  return std::shared_ptr<TyInfrule>(new ConsDivSubUrem(_val));
}
void ConsDivSubUrem::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("DivSubUrem");
  archive(CEREAL_NVP(div_sub_urem));
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

ConsGhost::ConsGhost(){
}
void ConsGhost::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Ghost");
}

ConsGlobal::ConsGlobal(){
}
void ConsGlobal::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Global");
}

ConsHalfType::ConsHalfType(){
}
void ConsHalfType::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("HalfType");
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

ConsInfrule::ConsInfrule(std::shared_ptr<TyPosition> _position, std::shared_ptr<TyInfrule> _infrule) : position(_position), infrule(_infrule){
}
void ConsInfrule::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Infrule");
  archive.startNode();
  archive.makeArray();
  archive(CEREAL_NVP(position));
  archive(CEREAL_NVP(infrule));
  archive.finishNode();
}

ConsIntType::ConsIntType(int _i) : i(_i){
}
void ConsIntType::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("IntType");
  archive(CEREAL_NVP(i));
}

ConsLessdef::ConsLessdef(std::shared_ptr<TyPropagateLessdef> _propagate_lessdef) : propagate_lessdef(_propagate_lessdef){
}
std::shared_ptr<TyPropagateObject> ConsLessdef::make(std::shared_ptr<TyExpr> _lhs, std::shared_ptr<TyExpr> _rhs, std::shared_ptr<TyScope> _scope){
  std::shared_ptr<TyPropagateLessdef> _val(new TyPropagateLessdef(_lhs, _rhs, _scope));
  return std::shared_ptr<TyPropagateObject>(new ConsLessdef(_val));
}
void ConsLessdef::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Lessdef");
  archive(CEREAL_NVP(propagate_lessdef));
}

ConsMaydiff::ConsMaydiff(std::shared_ptr<TyRegister> _register) : register(_register){
}
std::shared_ptr<TyPropagateObject> ConsMaydiff::make(std::string _name, std::shared_ptr<TyTag> _tag){
  std::shared_ptr<TyRegister> _val(new TyRegister(_name, _tag));
  return std::shared_ptr<TyPropagateObject>(new ConsMaydiff(_val));
}
void ConsMaydiff::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Maydiff");
  archive(CEREAL_NVP(register));
}

ConsMulAddDistributive::ConsMulAddDistributive(std::shared_ptr<TyMulAddDistributive> _mul_add_distributive) : mul_add_distributive(_mul_add_distributive){
}
std::shared_ptr<TyInfrule> ConsMulAddDistributive::make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _w){
  std::shared_ptr<TyMulAddDistributive> _val(new TyMulAddDistributive(_z, _x, _y, _w));
  return std::shared_ptr<TyInfrule>(new ConsMulAddDistributive(_val));
}
void ConsMulAddDistributive::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("MulAddDistributive");
  archive(CEREAL_NVP(mul_add_distributive));
}

ConsMulBool::ConsMulBool(std::shared_ptr<TyMulBool> _mul_bool) : mul_bool(_mul_bool){
}
std::shared_ptr<TyInfrule> ConsMulBool::make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y){
  std::shared_ptr<TyMulBool> _val(new TyMulBool(_z, _x, _y));
  return std::shared_ptr<TyInfrule>(new ConsMulBool(_val));
}
void ConsMulBool::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("MulBool");
  archive(CEREAL_NVP(mul_bool));
}

ConsMulCommutative::ConsMulCommutative(std::shared_ptr<TyMulCommutative> _mul_commutative) : mul_commutative(_mul_commutative){
}
std::shared_ptr<TyInfrule> ConsMulCommutative::make(std::shared_ptr<TyRegister> _z){
  std::shared_ptr<TyMulCommutative> _val(new TyMulCommutative(_z));
  return std::shared_ptr<TyInfrule>(new ConsMulCommutative(_val));
}
void ConsMulCommutative::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("MulCommutative");
  archive(CEREAL_NVP(mul_commutative));
}

ConsMulMone::ConsMulMone(std::shared_ptr<TyMulMone> _mul_mone) : mul_mone(_mul_mone){
}
std::shared_ptr<TyInfrule> ConsMulMone::make(std::shared_ptr<TyRegister> _z){
  std::shared_ptr<TyMulMone> _val(new TyMulMone(_z));
  return std::shared_ptr<TyInfrule>(new ConsMulMone(_val));
}
void ConsMulMone::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("MulMone");
  archive(CEREAL_NVP(mul_mone));
}

ConsMulNeg::ConsMulNeg(std::shared_ptr<TyMulNeg> _mul_neg) : mul_neg(_mul_neg){
}
std::shared_ptr<TyInfrule> ConsMulNeg::make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _mx, std::shared_ptr<TyRegister> _my){
  std::shared_ptr<TyMulNeg> _val(new TyMulNeg(_z, _mx, _my));
  return std::shared_ptr<TyInfrule>(new ConsMulNeg(_val));
}
void ConsMulNeg::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("MulNeg");
  archive(CEREAL_NVP(mul_neg));
}

ConsMulShl::ConsMulShl(std::shared_ptr<TyMulShl> _mul_shl) : mul_shl(_mul_shl){
}
std::shared_ptr<TyInfrule> ConsMulShl::make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _y){
  std::shared_ptr<TyMulShl> _val(new TyMulShl(_z, _y));
  return std::shared_ptr<TyInfrule>(new ConsMulShl(_val));
}
void ConsMulShl::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("MulShl");
  archive(CEREAL_NVP(mul_shl));
}

ConsNegVal::ConsNegVal(std::shared_ptr<TyNegVal> _neg_val) : neg_val(_neg_val){
}
std::shared_ptr<TyInfrule> ConsNegVal::make(std::shared_ptr<TyConstInt> _c1, std::shared_ptr<TyConstInt> _c2, std::shared_ptr<TySize> _sz){
  std::shared_ptr<TyNegVal> _val(new TyNegVal(_c1, _c2, _sz));
  return std::shared_ptr<TyInfrule>(new ConsNegVal(_val));
}
void ConsNegVal::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("NegVal");
  archive(CEREAL_NVP(neg_val));
}

ConsNoalias::ConsNoalias(std::shared_ptr<TyPropagateNoalias> _propagate_noalias) : propagate_noalias(_propagate_noalias){
}
std::shared_ptr<TyPropagateObject> ConsNoalias::make(std::shared_ptr<TyRegister> _lhs, std::shared_ptr<TyRegister> _rhs, std::shared_ptr<TyScope> _scope){
  std::shared_ptr<TyPropagateNoalias> _val(new TyPropagateNoalias(_lhs, _rhs, _scope));
  return std::shared_ptr<TyPropagateObject>(new ConsNoalias(_val));
}
void ConsNoalias::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Noalias");
  archive(CEREAL_NVP(propagate_noalias));
}

ConsPPCFP128Type::ConsPPCFP128Type(){
}
void ConsPPCFP128Type::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("PPC_FP128Type");
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

ConsPhinodeCurrentBlockName::ConsPhinodeCurrentBlockName(std::string _s) : s(_s){
}
void ConsPhinodeCurrentBlockName::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("PhinodeCurrentBlockName");
  archive(CEREAL_NVP(s));
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

ConsPropagate::ConsPropagate(std::shared_ptr<TyPropagate> _propagate) : propagate(_propagate){
}
std::shared_ptr<TyCommand> ConsPropagate::make(std::shared_ptr<TyPropagateObject> _propagate, std::shared_ptr<TyPropagateRange> _propagate_range){
  std::shared_ptr<TyPropagate> _val(new TyPropagate(_propagate, _propagate_range));
  return std::shared_ptr<TyCommand>(new ConsPropagate(_val));
}
void ConsPropagate::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Propagate");
  archive(CEREAL_NVP(propagate));
}

ConsRemNeg::ConsRemNeg(std::shared_ptr<TyRemNeg> _rem_neg) : rem_neg(_rem_neg){
}
std::shared_ptr<TyInfrule> ConsRemNeg::make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _my){
  std::shared_ptr<TyRemNeg> _val(new TyRemNeg(_z, _my));
  return std::shared_ptr<TyInfrule>(new ConsRemNeg(_val));
}
void ConsRemNeg::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("RemNeg");
  archive(CEREAL_NVP(rem_neg));
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

ConsSize::ConsSize(int _i) : i(_i){
}
void ConsSize::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Size");
  archive(CEREAL_NVP(i));
}

ConsSource::ConsSource(){
}
void ConsSource::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Source");
}

ConsSubAdd::ConsSubAdd(std::shared_ptr<TySubAdd> _sub_add) : sub_add(_sub_add){
}
std::shared_ptr<TyInfrule> ConsSubAdd::make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyValue> _my, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyValue> _y, std::shared_ptr<TySize> _sz){
  std::shared_ptr<TySubAdd> _val(new TySubAdd(_z, _my, _x, _y, _sz));
  return std::shared_ptr<TyInfrule>(new ConsSubAdd(_val));
}
void ConsSubAdd::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("SubAdd");
  archive(CEREAL_NVP(sub_add));
}

ConsSubConstAdd::ConsSubConstAdd(std::shared_ptr<TySubConstAdd> _sub_const_add) : sub_const_add(_sub_const_add){
}
std::shared_ptr<TyInfrule> ConsSubConstAdd::make(std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z){
  std::shared_ptr<TySubConstAdd> _val(new TySubConstAdd(_y, _z));
  return std::shared_ptr<TyInfrule>(new ConsSubConstAdd(_val));
}
void ConsSubConstAdd::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("SubConstAdd");
  archive(CEREAL_NVP(sub_const_add));
}

ConsSubConstNot::ConsSubConstNot(std::shared_ptr<TySubConstNot> _sub_const_not) : sub_const_not(_sub_const_not){
}
std::shared_ptr<TyInfrule> ConsSubConstNot::make(std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z){
  std::shared_ptr<TySubConstNot> _val(new TySubConstNot(_y, _z));
  return std::shared_ptr<TyInfrule>(new ConsSubConstNot(_val));
}
void ConsSubConstNot::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("SubConstNot");
  archive(CEREAL_NVP(sub_const_not));
}

ConsSubMone::ConsSubMone(std::shared_ptr<TySubMone> _sub_mone) : sub_mone(_sub_mone){
}
std::shared_ptr<TyInfrule> ConsSubMone::make(std::shared_ptr<TyRegister> _z){
  std::shared_ptr<TySubMone> _val(new TySubMone(_z));
  return std::shared_ptr<TyInfrule>(new ConsSubMone(_val));
}
void ConsSubMone::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("SubMone");
  archive(CEREAL_NVP(sub_mone));
}

ConsSubOnebit::ConsSubOnebit(std::shared_ptr<TySubOnebit> _sub_onebit) : sub_onebit(_sub_onebit){
}
std::shared_ptr<TyInfrule> ConsSubOnebit::make(std::shared_ptr<TyRegister> _z){
  std::shared_ptr<TySubOnebit> _val(new TySubOnebit(_z));
  return std::shared_ptr<TyInfrule>(new ConsSubOnebit(_val));
}
void ConsSubOnebit::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("SubOnebit");
  archive(CEREAL_NVP(sub_onebit));
}

ConsSubRemove::ConsSubRemove(std::shared_ptr<TySubRemove> _sub_remove) : sub_remove(_sub_remove){
}
std::shared_ptr<TyInfrule> ConsSubRemove::make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyValue> _a, std::shared_ptr<TyValue> _b, std::shared_ptr<TySize> _sz){
  std::shared_ptr<TySubRemove> _val(new TySubRemove(_z, _y, _a, _b, _sz));
  return std::shared_ptr<TyInfrule>(new ConsSubRemove(_val));
}
void ConsSubRemove::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("SubRemove");
  archive(CEREAL_NVP(sub_remove));
}

ConsSubRemove2::ConsSubRemove2(std::shared_ptr<TySubRemove2> _sub_remove2) : sub_remove2(_sub_remove2){
}
std::shared_ptr<TyInfrule> ConsSubRemove2::make(std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z){
  std::shared_ptr<TySubRemove2> _val(new TySubRemove2(_y, _z));
  return std::shared_ptr<TyInfrule>(new ConsSubRemove2(_val));
}
void ConsSubRemove2::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("SubRemove2");
  archive(CEREAL_NVP(sub_remove2));
}

ConsSubSdiv::ConsSubSdiv(std::shared_ptr<TySubSdiv> _sub_sdiv) : sub_sdiv(_sub_sdiv){
}
std::shared_ptr<TyInfrule> ConsSubSdiv::make(std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z){
  std::shared_ptr<TySubSdiv> _val(new TySubSdiv(_y, _z));
  return std::shared_ptr<TyInfrule>(new ConsSubSdiv(_val));
}
void ConsSubSdiv::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("SubSdiv");
  archive(CEREAL_NVP(sub_sdiv));
}

ConsSubShl::ConsSubShl(std::shared_ptr<TySubShl> _sub_shl) : sub_shl(_sub_shl){
}
std::shared_ptr<TyInfrule> ConsSubShl::make(std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z){
  std::shared_ptr<TySubShl> _val(new TySubShl(_x, _y, _z));
  return std::shared_ptr<TyInfrule>(new ConsSubShl(_val));
}
void ConsSubShl::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("SubShl");
  archive(CEREAL_NVP(sub_shl));
}

ConsTarget::ConsTarget(){
}
void ConsTarget::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("Target");
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

ConsX86FP80Type::ConsX86FP80Type(){
}
void ConsX86FP80Type::serialize(cereal::JSONOutputArchive& archive) const{
  archive.makeArray();
  archive.writeName();
  archive.saveValue("X86_FP80Type");
}

