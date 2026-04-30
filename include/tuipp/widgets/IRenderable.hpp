#pragma once

namespace tuipp {

namespace widgets {

/// The base class for every widgets, exposed so you can create your own!
class IRenderable
{
  public:
    virtual void render(const int& width) const = 0;
    virtual int get_lenght() const              = 0;
};

} // namespace widgets

} // namespace tuipp
