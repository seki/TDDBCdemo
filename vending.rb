require 'test/unit'

class Vending
  def initialize
    @amount = 0
  end
  attr_reader :amount

  def drop_in(money)
    @amount += money
  end
end

class TestVending < Test::Unit::TestCase
  def setup
    @v = Vending.new
  end

  def test_core
    assert_equal(0, @v.amount)

    @v.drop_in(10)
    assert_equal(10, @v.amount)

    @v.drop_in(10)
    @v.drop_in(100)
    assert_equal(120, @v.amount)
    
  end
end
