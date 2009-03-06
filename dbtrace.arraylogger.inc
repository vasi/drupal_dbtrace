<?php

class arraylogger implements ArrayAccess, Iterator {
    private $internal = array();
    private $callback;
    
    public function __construct($callback) {
      $this->callback = $callback;
    }
    
    public function offsetSet($offset, $value) {
        $this->internal[$offset] = $value;
        call_user_func($this->callback, $value);
    }
    
    public function offsetExists($offset) {
        return array_key_exists($offset, $this->internal);
    }
    
    public function offsetGet($offset) {
        return $this->internal[$offset];
    }
    
    public function offsetUnset($offset) {
        unset($this->internal[$offset]);
    }
    
    public function current() { return current($this->internal); }
    public function key() { return key($this->internal); }
    public function valid() { return current($this->internal); }
    public function next() { next($this->internal); }
    public function rewind() { reset($this->internal); }
}
