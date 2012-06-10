require 'test/unit'

class Vending
  Item = Struct.new(:price, :stock, :name)

  def initialize
    @amount = 0
    @sales_amount = 0
    @item = Item.new
    @item.price = 120
    @item.stock = 5
    @item.name = 'Cola'
  end
  attr_reader :amount, :sales_amount, :item

  def drop_in(money)
    return false unless [10, 50, 100, 500, 1000].include?(money)
    @amount += money
    true
  end

  def can_buy?
    @amount >= @item.price && @item.stock > 0
  end

  def buy
    return false unless can_buy?
    @amount -= @item.price
    @sales_amount += @item.price
    @item.stock -= 1
    true
  end

  def cancel
    @amount
  ensure
    @amount = 0
  end
end

class TestVending < Test::Unit::TestCase
  def setup
    @v = Vending.new
  end

  def test_drop_in
    assert(! @v.drop_in(1))
    assert(! @v.drop_in(5))
    assert(@v.drop_in(10))
    assert(@v.drop_in(50))
    assert(@v.drop_in(100))
    assert(@v.drop_in(500))
    assert(@v.drop_in(1000))
    assert_equal(1660, @v.amount)
  end

  def test_buy
    assert_equal(0, @v.amount)
    assert_equal(0, @v.sales_amount)
    assert_equal(120, @v.item.price)
    assert_equal(5, @v.item.stock)
    assert_equal('Cola', @v.item.name)

    assert(! @v.buy)
    assert_equal(120, @v.item.price)
    assert_equal(5, @v.item.stock)
    assert_equal('Cola', @v.item.name)

    @v.drop_in(10)
    @v.drop_in(10)
    assert(! @v.can_buy?)

    @v.drop_in(100)
    assert_equal(120, @v.amount)
    assert(@v.can_buy?)
    assert_equal(0, @v.sales_amount)

    assert(@v.buy)
    assert_equal(0, @v.amount)
    assert_equal(120, @v.sales_amount)
    
    @v.drop_in(1000)
    assert(@v.can_buy?)
    assert(@v.buy)
    assert(@v.buy)
    assert(@v.buy)
    assert(@v.buy)
    assert(! @v.buy)
    assert_equal(600, @v.sales_amount)

    assert_equal(520, @v.amount)
    assert_equal(520, @v.cancel)
    assert_equal(0, @v.amount)
    assert_equal(0, @v.cancel)
  end
end
