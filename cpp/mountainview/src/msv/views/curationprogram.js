var clusters=[];
function setup_clusters() {
    var cluster_numbers=_CP.clusterNumbers();
    cluster_numbers=JSON.parse(cluster_numbers);
    for (var i in cluster_numbers) {
        var C=new _Cluster(cluster_numbers[i]);
        clusters.push(C);
    }
}

function _Cluster(num) {
    this.k=function() {
        return num;
    }
    this.metric=function(metric_name) {
        return _CP.metric(num,metric_name);
    }
    this.setMetric=function(metric_name,val) {
        return _CP.setMetric(num,metric_name,val);
    }
    this.hasTag=function(tag_name) {
        return _CP.hasTag(num,tag_name);
    }
    this.addTag=function(tag_name) {
        _CP.addTag(num,tag_name);
    }
    this.removeTag=function(tag_name) {
        _CP.removeTag(num,tag_name);
    }
}

var clusterPairs=[];
function setup_cluster_pairs() {
    var cluster_pairs=_CP.clusterPairs();
    cluster_pairs=JSON.parse(cluster_pairs);
    for (var ii in cluster_pairs) {
        var C=new _ClusterPair(cluster_pairs[ii]);
        clusterPairs.push(C);
    }
}

function _ClusterPair(pair) {
    this.k1=function() {
        return pair.k1;
    }
    this.k2=function() {
        return pair.k2;
    }
    this.cluster1=function() {
        return new _Cluster(pair.k1);
    }
    this.cluster2=function() {
        return new _Cluster(pair.k2);
    }

    this.metric=function(metric_name) {
        return _CP.pairMetric(pair.k1,pair.k2,metric_name);
    }
    this.setMetric=function(metric_name,val) {
        return _CP.setPairMetric(pair.k1,pair.k2,metric_name,val);
    }
    /*
    this.addTag=function(tag_name) {
        console.log('ADDING TAG: '+num+' '+tag_name);
        _CP.addTag(num,tag_name);
    }
    this.removeTag=function(tag_name) {
        _CP.removeTag(num,tag_name);
    }
    */
}


var console={
    log:function(msg) {
        if ((typeof msg)!='string')
            msg=JSON.stringify(msg);
        _CP.log(msg);
    }
};

setup_clusters();
setup_cluster_pairs();
