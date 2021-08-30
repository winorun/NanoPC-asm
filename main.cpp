#include "Parser.h"
#include <stdio.h>
#include <fstream>

int line=1;
std::vector<unsigned char> g_programm;
std::map<std::string,unsigned char> map_value; 
std::map<std::string,unsigned char> map_label;
std::map<std::string,std::list<unsigned char>> map_label_list;
std::map<std::string,unsigned char> map_command{ 
  { "nup", 0x00 }, 
  { "halt", 0x01 }, 
  { "stop", 0x02 }, 
  { "jmp", 0b00001000 }, 
  { "mov", 0x10 }, 
  { "add", 0x20 }, 
  { "sub", 0x30 },
  { "cmp", 0x40 }, 
  { "je",  0x50 }, 
  { "jne", 0x60 }, 
  { "joe", 0x70 }, 
  { "and", 0x80 }, 
  { "xor", 0x90 }, 
  { "or",  0xA0 },
  { "rol", 0xB0 },
  { "ror", 0xC0 },
  { "jsr", 0xD0 }, 
  { "pull", 0xE0 },
  { "push", 0xF0 },
};
std::map<std::string,unsigned char> map_reg{ 
  { "R0", 0x00 }, 
  { "R1", 0x01 }, 
  { "R2", 0x02 }, 
  { "R3", 0x03 }, 
  { "R4", 0x04 }, 
  { "R5", 0x05 }, 
  { "R6", 0x06 }, // SP SV | SD TV TD KV KC RC PS PC
  { "R7", 0x07 }, 
  { "R8", 0x08 }, 
  { "R9", 0x09 }, 
  { "Ra", 0x0A }, 
  { "Rb", 0x0B }, 
  { "Rc", 0x0C }, 
  { "Rd", 0x0D }, 
  { "Re", 0x0E }, 
  { "Rf", 0x0F },
  { "SP", 0x06 }, // SP SV | SD TV TD KV KC RC PS PC
  { "SV", 0x07 }, 
  { "SD", 0x08 }, 
  { "TV", 0x09 }, 
  { "TD", 0x0A }, 
  { "KV", 0x0B }, 
  { "KC", 0x0C }, 
  { "RC", 0x0D }, 
  { "PS", 0x0E }, 
  { "PC", 0x0F },
};


int main(int argc, char **argv)
{
    std::ifstream iFile = std::ifstream();
    if(argc == 2){
        iFile.open(argv[1]);
        if (!iFile) {
            std::cerr << "Не могу открыть файл " << argv[1] << std::endl; 
            return 1;
        }
    }
  Parser parser{iFile ? static_cast<::std::istream &>(iFile) : static_cast<::std::istream &>(::std::cin)};
  parser.parse();
  if(iFile)iFile.close();
  for(auto &i:map_label_list)
      for(auto j:i.second)
          g_programm[j]=map_label[i.first];
  {
      int i=0;
      for (unsigned char byte:g_programm) {
        if(i%0x10 == 0)printf("\n %02X |", i);
        if(i%0x10 == 8)printf(" | ");
        printf(" %02X",byte);
        i++;
      }
  }
  printf("\n");
 
  printf("lines: %i\n",line);
//  printf("size: %i\n",g_programm.size());
  g_programm.resize(256,0);
  std::ofstream file("out.bin",std::ios_base::binary);
  file.write((char *)g_programm.data(), g_programm.size());
  file.close();
}

