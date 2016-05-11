struct TyFloatType{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};

struct ConsDoubleType : public TyFloatType{
public : 
  ConsDoubleType();
  void serialize(cereal::JSONOutputArchive& archive) const;
};

struct ConsFP128Type : public TyFloatType{
public : 
  ConsFP128Type();
  void serialize(cereal::JSONOutputArchive& archive) const;
};

struct ConsFloatType : public TyFloatType{
public : 
  ConsFloatType();
  void serialize(cereal::JSONOutputArchive& archive) const;
};

struct ConsHalfType : public TyFloatType{
public : 
  ConsHalfType();
  void serialize(cereal::JSONOutputArchive& archive) const;
};

struct ConsPPCFP128Type : public TyFloatType{
public : 
  ConsPPCFP128Type();
  void serialize(cereal::JSONOutputArchive& archive) const;
};

struct ConsX86FP80Type : public TyFloatType{
public : 
  ConsX86FP80Type();
  void serialize(cereal::JSONOutputArchive& archive) const;
};

