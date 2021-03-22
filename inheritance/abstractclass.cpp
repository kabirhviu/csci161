#include <iostream>
#include <string>

using namespace std;

const string JPEG = "200";
const string MPEG = "300";
const string QUICK  ="400";

//Runtime polymorphism allows you to assign
//any subclass object to a super class reference
//or pointer and get the overriden method of
//the subclass get executed although you call
//the method through superclass reference or pointer.
//The binding between the method name and the its code
//happens at run time.
//Runtime binding binds the method name with the code
//of the class from which the actual object is made of.
//Runtime polymorphism with an abstract class.
//Abstract class, must have at least one
//pure virtual function.
//It is not possible to create object from
//the abstract class.
//It is, however, possible to create reference
//or pointer using an abstract class.
class Codec {
public:
  //Pure virtual function
  //Subclass must override this pure virtual function
  //If subclass does not override this function, the
  //subclass will become an abstract class
  virtual int encode(int)=0;

  //Pure virtual function
  virtual int decode(int)=0;
};

class CodecJPEG : public Codec {
public:
  int encode (int raw) {
    cout<<raw<<" encoded by CodecJPEG..."<<endl;
    int jpeg = stoi(JPEG);
    return raw + jpeg/8;
  }

  int decode (int encoded) {
    cout<<encoded<<" decoded by CodecJPEG..."<<endl;
    int jpeg = stoi(JPEG);
    return encoded - jpeg/8;
  }
};

class CodecMPEG : public Codec {
public:
  int encode (int raw) {
    cout<<raw<<" encoded by CodecMPEG..."<<endl;
    int mpeg = stoi(MPEG);
    return raw + mpeg/6;
  }

  int decode (int encoded) {
    cout<<encoded<<" decoded by CodecMPEG..."<<endl;
    int mpeg = stoi(MPEG);
    return encoded - mpeg/6;
  }
};

class CodecQuick : public Codec {
public:
  int encode (int raw) {
    cout<<raw<<" encoded by CodecQuick..."<<endl;
    int quick = stoi(QUICK);
    return raw + quick/10;
  }

  int decode (int encoded) {
    cout<<encoded<<" decoded by CodecQuick..."<<endl;
    int quick = stoi(QUICK);
    return encoded - quick/10;
  }
};

int main() {
  //Cannot instantiate an object from an abstract class
  //Codec codec;
  CodecJPEG codecJPEG;
  CodecMPEG codecMPEG;
  CodecQuick codecQuick;

  int raw = 100;
  cout<<codecJPEG.encode(raw)<<endl;
  cout<<codecMPEG.encode(raw)<<endl;
  cout<<codecQuick.encode(raw)<<endl;

  cout<<"Runtime polymorphism with abstract class..."<<endl;

  // Codec& refToCodec = codec;
  // Codec& refToCodec = codecJPEG;
  Codec& refToCodec = codecMPEG;
  // Codec& refToCodec = codecQuick;
  cout<<refToCodec.encode(raw)<<endl;

  return 0;
}
