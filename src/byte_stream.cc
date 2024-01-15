#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : capacity_( capacity ) {}

bool Writer::is_closed() const
{
  // Your code here.
  return this->is_close;
}

void Writer::push( string data )
{
  // Your code here.
  auto actual_push = min(data.size(), this->available_capacity());
  if(actual_push == 0) return;
  data = data.substr(0, actual_push);
  stream_buf.push_back(data);
  push_count += actual_push;
  buffer_count += actual_push;
  capacity_ -= actual_push;
  return;
}

void Writer::close()
{
  this->is_close = true;
}

uint64_t Writer::available_capacity() const
{
  // Your code here.
  return this->capacity_;
}

uint64_t Writer::bytes_pushed() const
{
  // Your code here.
  return this->push_count;
}

bool Reader::is_finished() const
{
  // Your code here.
  if((this->is_close) && (!this->bytes_buffered()))
    return true;
  return false;
}

uint64_t Reader::bytes_popped() const
{
  // Your code here.
  return this->pop_count;
}

string_view Reader::peek() const
{
  // Your code here.
  return this->stream_buf[0];
}

void Reader::pop( uint64_t len )
{
  // Your code here.
  auto actual_pop = min(len, this->buffer_count);
  if(actual_pop == 0) return;
  auto strbgn = stream_buf.begin();
  uint64_t tmpcnt = 0;
  while(tmpcnt < actual_pop) {
    tmpcnt += (*strbgn).size();
    ++strbgn;
  }
  --strbgn;
  tmpcnt -= (*strbgn).size();
  stream_buf.assign(strbgn, stream_buf.end());
  auto pp = actual_pop - tmpcnt;
  if(pp == stream_buf[0].size()) stream_buf.assign(stream_buf.begin() + 1, stream_buf.end());
  else stream_buf[0] = stream_buf[0].substr(pp, stream_buf[0].size());


  pop_count += actual_pop;
  buffer_count -= actual_pop;
  capacity_ += actual_pop;
  return;
}

uint64_t Reader::bytes_buffered() const
{
  // Your code here.
  return this->buffer_count;
}
