require 'test/unit'

class Vending
  Item = Struct.new(:price, :stock, :name)

  def initialize
    @amount = 0
    @item = Item.new
    @item.price = 120
    @item.stock = 5
    @item.name = 'Cola'
  end
  attr_reader :amount, :item

  def drop_in(money)
    @amount += money
  end
end

class TestVending < Test::Unit::TestCase
  def setup
    @v = Vending.new
  end

  def test_buy
    assert_equal(0, @v.amount)
    assert_equal(120, @v.item.price)
    assert_equal(5, @v.item.stock)
    assert_equal('Cola', @v.item.name)


    @v.drop_in(10)
    @v.drop_in(10)
    @v.drop_in(100)
    assert_equal(120, @v.amount)

  end
end
