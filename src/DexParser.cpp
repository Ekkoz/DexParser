// MIT License
// 
// Copyright (c) 2018 EkkoZ
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <fcntl.h>
#include <unistd.h>

#include "DexParser.hpp"

DexParser::DexParser()
{
}

DexParser::~DexParser()
{
}

bool DexParser::parseFromFile(const std::string &filename)
{
  int fd;
  std::int64_t length;
  byte *buffer;

  if ((fd = ::open(filename.c_str(), O_RDONLY)) < 0)
    return (false);
  else if ((length = ::lseek(fd, 0, SEEK_END)) < 0)
  {
    ::close(fd);
    return (false);
  }
  ::lseek(fd, 0, SEEK_SET);
  if ((buffer = (byte *) malloc(sizeof(*buffer) * length)) == NULL)
  {
    ::close(fd);
    return (false);
  }
  else if (::read(fd, buffer, length) != length)
  {
    ::close(fd);
    return (false);
  }
  return (true);
}

bool DexParser::parseFromBuffer(const byte *buffer, std::size_t length)
{
  return (true);
}