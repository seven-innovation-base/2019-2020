from tensorflow.examples.tutorials.mnist import input_data
import tensorflow as tf
import os
import cv2
import numpy as np
os.chdir('G:/机器学习/泰迪杯学习/tensorflow学习/6 模型保存与调用')
tf.reset_default_graph()   # 重置计算图,清除以前的图，就是在一块干净的画布上进行工作
mnist = input_data.read_data_sets('MNIST_data', one_hot=True)   # 读取数据
x_data = tf.placeholder(tf.float32, [None, 784], name='input')  # 占位符：样本自变量
y_data = tf.placeholder(tf.float32, [None, 10])   # 占位符：样本目标变量

w = tf.Variable(tf.zeros([784, 10]))   # 网络权值矩阵
bias = tf.Variable(tf.zeros([10]))     # 网络阈值
y = tf.nn.softmax(tf.matmul(x_data, w) + bias, name='output')   # 网络输出

cross_entropy = tf.reduce_mean(-tf.reduce_sum(y_data*tf.log(y), axis=1))  # 交叉熵（损失函数）
optimizer = tf.train.GradientDescentOptimizer(0.03)   # 梯度下降法优化器
train = optimizer.minimize(cross_entropy)   # 训练节点
acc = tf.reduce_mean(tf.cast(tf.equal(tf.argmax(y, axis=1), tf.argmax(y_data, axis=1)), dtype=tf.float32))  # 模型预测值与样本实际值比较的精度
saver = tf.train.Saver()

sess = tf.Session()  # 启动会话
sess.run(tf.global_variables_initializer())  # 执行变量初始化操作
for i in range(20000):
    x_s, y_s = mnist.train.next_batch(100)
    if i%1000 == 0:
        acc_tr = sess.run(acc, feed_dict={x_data: x_s, y_data: y_s})
        print(i, '轮训练的精度', acc_tr)
    sess.run(train, feed_dict={x_data:x_s, y_data:y_s})   # 模型训练

acc_te = sess.run(acc, feed_dict={x_data:mnist.test.images, y_data:mnist.test.labels})  # 测试集精度
print('模型测试精度：', acc_te)
saver.save(sess, './model/softmax_model')
sess.close()


path = './testimages/'
tf.reset_default_graph()  # 重置计算图
sess = tf.Session()
saver = tf.train.import_meta_graph('./model/softmax_model.meta')
saver.restore(sess, './model/softmax_model')
graph = tf.get_default_graph()  # 获取当前计算图
input = graph.get_tensor_by_name('input:0')    # 模型输入节点
output = graph.get_tensor_by_name('output:0')  # 模型输出节点

for i in range(30):
    img = cv2.imread(path + str(i) +'.jpg')[:, :, 0] / 255  # 读取图片数据
    img = img.reshape([1, 28 * 28])  # 进行维度转化
    pre = sess.run(output, feed_dict={input: img})  # 将新样本放入模型中进行预测
    res = np.argmax(pre, 1)   # 预测标签
    print('图片 ', str(i)+'.jpg 中的数字是: ', res[0])
sess.close()