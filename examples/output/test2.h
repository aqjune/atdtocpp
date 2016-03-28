class TyFloatType{
public : 
  virtual void serialize(JSONOutputArchive& archive) const = 0;

};
class ConsHalfType : public TyFloatType{
public : 
  ConsHalfType();
  void serialize(JSONOutputArchive& archive) const;

};
class ConsFloatType : public TyFloatType{
public : 
  ConsFloatType();
  void serialize(JSONOutputArchive& archive) const;

};
class ConsDoubleType : public TyFloatType{
public : 
  ConsDoubleType();
  void serialize(JSONOutputArchive& archive) const;

};
class ConsFP128Type : public TyFloatType{
public : 
  ConsFP128Type();
  void serialize(JSONOutputArchive& archive) const;

};
class ConsPPCFP128Type : public TyFloatType{
public : 
  ConsPPCFP128Type();
  void serialize(JSONOutputArchive& archive) const;

};
class ConsX86FP80Type : public TyFloatType{
public : 
  ConsX86FP80Type();
  void serialize(JSONOutputArchive& archive) const;

};
