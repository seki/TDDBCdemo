TDDBC大阪の課題
=============

Cでやる
------

assert.hがあれば充分な気がするぜ。

    % cc vending.c && ./a.out && git add vending.c && git commit -m 'no comment'


Rubyでもやった
-------------

RSpecはRSpec道がありそうだったのでスルー。

    % ruby vending.rb && git add vending.rb && git commit -m 'no comment' 


わたしの進め方
------------

課題のステップ0から3までをやりました。が、作った順序は課題のステップ順ではありません。

1. 仕様を全部読む
2. 最低限の仕様を考える → お金を入れて買うまでだと自動販売機っぽいのでそれを基本と思う。
3. どこの部分を書くか決める → UIと具に分けて考えてみた。出力するのはUIなので振る舞いだけを担当する「具」を書くことにした。
4. 基本のシナリオをだんだん大きくしながらその状況で確認できることを追加してく
5. 「ステップ1 扱えないお金」は枝葉っぽい仕様なので後回しに → シナリオも独立に

仕事のときっぽい解き方を意識したのでこんな手順。ステップ4以降はチラ見したけど、あえて意識しないようにしてみました。

