import os
import zipfile
from flask import Flask, request, redirect, url_for, flash, render_template
from werkzeug.utils import secure_filename
import base64
import io
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt
def build_graph(x_coordinates, y_coordinates):
    img = io.BytesIO()
    plt.plot(x_coordinates, y_coordinates)
    plt.savefig(img, format='png')
    img.seek(0)
    graph_url = base64.b64encode(img.getvalue()).decode()
    plt.close()
    return 'data:image/png;base64,{}'.format(graph_url)

UPLOAD_FOLDER = os.path.dirname(os.path.realpath(__file__))
ALLOWED_EXTENSIONS = set(['zip'])

app = Flask(__name__)

def allowed_file(filename):
    return '.' in filename and \
           filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS

@app.route('/', methods=['GET', 'POST'])
def upload_file():
    if request.method == 'POST':
        # check if the post request has the file part
        if 'file' not in request.files:
            flash('No file part')
            return redirect(request.url)
        file = request.files['file']
        # if user does not select file, browser also
        # submit a empty part without filename
        if file.filename == '':
            flash('No selected file')
            return redirect(request.url)
        if file and allowed_file(file.filename):
            filename = secure_filename(file.filename)
            file.save(os.path.join(UPLOAD_FOLDER, filename))
            zip_ref = zipfile.ZipFile(os.path.join(UPLOAD_FOLDER, filename), 'r')
            zip_ref.extractall(UPLOAD_FOLDER)
            zip_ref.close()
            f=open("abc.txt","r")
            all_text=f.readlines()
            '''all_text=["Google and Facebook are strangling the free press to death. Democracy is the loserGoogle an", "Your 60-second guide to security stuff Google touted today at Next 18","A Guide to Using Android Without Selling Your Soul to Google","Review: Lenovo’s Google Smart Display is pretty and intelligent","Google Maps user spots mysterious object submerged off the coast of Greece - and no-one knows what it is","Android is better than IOS","In information retrieval, tf–idf or TFIDF, short for term frequency–inverse document frequency","is a numerical statistic that is intended to reflect","how important a word is to a document in a collection or corpus.","It is often used as a weighting factor in searches of information retrieval","text mining, and user modeling. The tf-idf value increases proportionally","to the number of times a word appears in the document","and is offset by the frequency of the word in the corpus"]'''
            tfidf_vectorizer=TfidfVectorizer()
            tfidf=tfidf_vectorizer.fit_transform(all_text)
            kmeans=KMeans(n_clusters=6).fit(tfidf)
            lines_for_predicting=["tf and idf is awesome!", "some androids is there"]
            x=kmeans.predict(tfidf_vectorizer.transform(lines_for_predicting))
            x=x.tolist()
            for i in range(len(x)):
                x[i]=str(x[i])
            return " ".join(x)
    return render_template('index.html')


if __name__ == "__main__":
    app.run(debug=True)




























































'''"Google and Facebook are strangling the free press to death. Democracy is the loserGoogle an", "Your 60-second guide to security stuff Google touted today at Next 18","A Guide to Using Android Without Selling Your Soul to Google","Review: Lenovo’s Google Smart Display is pretty and intelligent","Google Maps user spots mysterious object submerged off the coast of Greece - and no-one knows what it is","Android is better than IOS","In information retrieval, tf–idf or TFIDF, short for term frequency–inverse document frequency","is a numerical statistic that is intended to reflect","how important a word is to a document in a collection or corpus.","It is often used as a weighting factor in searches of information retrieval","text mining, and user modeling. The tf-idf value increases proportionally","to the number of times a word appears in the document","and is offset by the frequency of the word in the corpus"'''
