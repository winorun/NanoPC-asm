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
  { "end", 0x01 }, 
  { "stop", 0x02 }, 
  { "jmp", 0b00000100 }, 
  { "mov", 0x10 }, 
  { "add", 0x20 }, 
  { "sub", 0x30 }, 
  { "je",  0x40 }, 
  { "jne", 0x50 }, 
  { "joe", 0x60 }, 
  { "and", 0x70 }, 
  { "xor", 0x80 }, 
  { "or",  0x90 }, 
};
std::map<std::string,unsigned char> map_reg{ 
  { "R0", 0x00 }, 
  { "R1", 0x01 }, 
  { "R2", 0x02 }, 
  { "R3", 0x03 }, 
  { "R4", 0x04 }, 
  { "R5", 0x05 }, 
  { "R6", 0x06 }, 
  { "R7", 0x07 }, 
  { "R8", 0x08 }, 
  { "R9", 0x09 }, 
  { "Ra", 0x0A }, 
  { "Rb", 0x0A }, 
  { "Rc", 0x0A }, 
  { "Rd", 0x0A }, 
  { "Re", 0x0A }, 
  { "Rf", 0x0A }, 
};


int main(int argc, char **argv)
{

  Parser parser;
  parser.parse();
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
  printf("size: %i\n",g_programm.size());
  g_programm.resize(256,0);
  std::ofstream file("out.bin",std::ios_base::binary);
  file.write((char *)g_programm.data(), g_programm.size());
  file.close();
}

