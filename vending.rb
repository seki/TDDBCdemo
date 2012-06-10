require 'test/unit'

class Foo
  def foo
    'foo'
  end
end

class TestFoo < Test::Unit::TestCase
  def test_core
    foo = Foo.new
    assert_equal('foo', foo.foo)
  end
end
