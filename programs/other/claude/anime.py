from manimlib import *

class VisualizeLinkedList(Scene):
    def construct(self):
        # リンクリストのノードを表すクラス
        class Node(VGroup):
            def __init__(self, val, left=None, right=None):
                super().__init__()
                self.val = val
                self.left = left
                self.right = right
                self.circle = Circle(radius=0.5, fill_color=BLUE, fill_opacity=0.5)
                self.text = Text(str(val), font_size=24)
                self.add(self.circle, self.text)
                if self.left:
                    self.left_arrow = Arrow(self.circle.get_left(), self.left.circle.get_right(), buff=0.1)
                    self.add(self.left_arrow)
                if self.right:
                    self.right_arrow = Arrow(self.circle.get_right(), self.right.circle.get_left(), buff=0.1)
                    self.add(self.right_arrow)

        # リンクリストの初期状態を作成
        head = Node(-1)  # ダミーノード
        current = head
        values = [2, 1, 4, 3]
        for val in values:
            new_node = Node(val, left=current)
            current.right = new_node
            current = new_node
        linked_list = head.right  # ダミーノードの次から開始

        # リンクリストを描画
        self.play(FadeIn(linked_list))
        self.wait()

        # 操作1: 1を4の次に5を挿入
        self.play(Indicate(linked_list[1].circle))  # 1を示す
        self.play(Indicate(linked_list[3].circle))  # 4を示す
        new_node = Node(5, left=linked_list[3], right=linked_list[3].right)
        linked_list[3].right.left = new_node
        linked_list[3].right = new_node
        self.play(FadeIn(new_node))
        self.wait()

        # 操作2: 2を削除
        self.play(Indicate(linked_list[0].circle))  # 2を示す
        linked_list[0].right.left = None
        self.play(FadeOut(linked_list[0]))
        self.remove(linked_list[0])
        self.wait()

        # 最終的なリンクリストを表示
        self.play(linked_list.arrange, RIGHT, run_time=2)
        self.wait()

# animatorオブジェクトを作成してシーンを実行
animator = Animator(VisualizeLinkedList)
animator.render()