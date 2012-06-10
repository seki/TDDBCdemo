require 'test/unit'

class Vending
  def initialize
    @amount = 0
  end
  attr_reader :amount
end

class TestVending < Test::Unit::TestCase
  def setup
    @v = Vending.new
  end

  def test_core
    assert_equal(0, @v.amount)
  end
end
