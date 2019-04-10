#include <iostream>
#include <string>

using namespace std;

const string JPEG = "200";
const string MPEG = "300";
const string QUICK  ="400";


class Codec {
public:
  int encode(int raw) {
    cout<<raw<<" encoded by Codec..."<<endl;
    return raw;
  }
  int decode(int encoded) {
    cout<<encoded<<" decoded by Codec..."<<endl;
    return encoded;
  }
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
  Codec codec;
  CodecJPEG codecJPEG;
  CodecMPEG codecMPEG;
  CodecQuick codecQuick;
  int raw = 100;
  cout<<codec.encode(raw)<<endl;
  cout<<codecJPEG.encode(raw)<<endl;
  cout<<codecMPEG.encode(raw)<<endl;
  cout<<codecQuick.encode(raw)<<endl;

  cout<<"No runtime polymorphism...."<<endl;
  // Codec& refToCodec = codec;
  //Calls encode() from Codec class
  // cout<<refToCodec.encode(raw)<<endl;
  // Codec& refToCodec = codecJPEG;
  //Still calls encode() from Codec class
  //although the object is from CodecJPEG class
  // cout<<refToCodec.encode(raw)<<endl;
  Codec& refToCodec = codecMPEG;
  //Still calls encode() from Codec class
  //although the object is from CodecMPEG class
  cout<<refToCodec.encode(raw)<<endl;
  // Codec& refToCodec = codecQuick;
  //Still calls encode() from Codec class
  //although the object is from CodecQuick class
  // cout<<refToCodec.encode(raw)<<endl;

  return 0;
}
